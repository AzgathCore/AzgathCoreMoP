/*
* Copyright 2023 AzgathCore
*
* This program is free software; you can redistribute it and/or modify it
* under the terms of the GNU General Public License as published by the
* Free Software Foundation; either version 2 of the License, or (at your
* option) any later version.
*
* This program is distributed in the hope that it will be useful, but WITHOUT
* ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
* FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
* more details.
*
* You should have received a copy of the GNU General Public License along
* with this program. If not, see <http://www.gnu.org/licenses/>.
*/

#include "MapUpdater.h"
#include "DelayExecutor.h"
#include "Map.h"
#include "MapInstanced.h"
#include "DatabaseEnv.h"

#include <ace/Guard_T.h>
#include <ace/Method_Request.h>

thread_local Map* CurrentMap = nullptr;

class WDBThreadStartReq1 : public ACE_Method_Request
{
    public:

        WDBThreadStartReq1()
        {
        }

        virtual int call()
        {
            return 0;
        }
};

class WDBThreadEndReq1 : public ACE_Method_Request
{
    public:

        WDBThreadEndReq1()
        {
        }

        virtual int call()
        {
            return 0;
        }
};

class MapUpdateRequest : public ACE_Method_Request
{
    private:

        Map& m_map;
        MapUpdater& m_updater;
        ACE_UINT32 m_diff;

    public:

        MapUpdateRequest(Map& m, MapUpdater& u, ACE_UINT32 d)
            : m_map(m), m_updater(u), m_diff(d)
        {
        }

        virtual int call()
        {
            CurrentMap = &m_map;
            m_map.Update (m_diff);
            CurrentMap = nullptr;
            m_updater.update_finished();
            return 0;
        }
};

MapUpdater::MapUpdater():
m_executor(), m_mutex(), m_condition(m_mutex), pending_requests(0) { }

MapUpdater::~MapUpdater()
{
    deactivate();
}

int MapUpdater::activate(size_t num_threads)
{
    return m_executor.start((int)num_threads, new WDBThreadStartReq1, new WDBThreadEndReq1);
}

int MapUpdater::deactivate()
{
    wait();

    return m_executor.deactivate();
}

int MapUpdater::wait()
{
    TRINITY_GUARD(ACE_Thread_Mutex, m_mutex);

    while (pending_requests > 0)
        m_condition.wait();

    return 0;
}

int MapUpdater::schedule_update(Map& map, ACE_UINT32 diff)
{
    MapUpdateRequest* rq = new MapUpdateRequest(map, *this, diff);
    rq->priority(calculate_priority(map));

    TRINITY_GUARD(ACE_Thread_Mutex, m_mutex);

    ++pending_requests;

    if (m_executor.execute(rq) == -1)
    {
        ACE_DEBUG((LM_ERROR, ACE_TEXT("(%t) \n"), ACE_TEXT("Failed to schedule Map Update")));

        --pending_requests;
        return -1;
    }

    return 0;
}

bool MapUpdater::activated()
{
    return m_executor.activated();
}

void MapUpdater::update_finished()
{
    TRINITY_GUARD(ACE_Thread_Mutex, m_mutex);

    if (pending_requests == 0)
    {
        ACE_ERROR((LM_ERROR, ACE_TEXT("(%t)\n"), ACE_TEXT("MapUpdater::update_finished BUG, report to devs")));
        return;
    }

    --pending_requests;

    m_condition.broadcast();
}

uint32 MapUpdater::calculate_priority(Map& map)
{
    // MapInstanced, priority high, based on instanced maps count, we need to spawn updates for each instance
    if (!map.GetInstanceId() && map.Instanceable())
        return 3 * ((MapInstanced&)map).GetInstancedMaps().size();

    // InstanceMap, raid, priority normal, based on players count and last update time
    // "Lagging" instances commonly lags at most times
    if (map.IsRaid())
        return map.GetPlayers().getSize() * map.GetUpdateTime() / 2;

    // All others map. 5 people dungeons will have a lower priority, global maps - higher
    return map.GetPlayers().getSize();
}
