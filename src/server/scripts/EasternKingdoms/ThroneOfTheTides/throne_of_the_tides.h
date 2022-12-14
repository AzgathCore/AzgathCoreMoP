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

#ifndef DEF_THRONEOFTHETIDES_H
#define DEF_THRONEOFTHETIDES_H

enum CreatureIds
{
    NPC_LADY_NAZJAR_EVENT       = 39959,
    NPC_LADY_NAZJAR             = 40586,
    NPC_COMMANDER_ULTHOK        = 40765,
    NPC_ERUNAK_STONESPEAKER     = 40825,
    NPC_MINDBENDER_GHURSHA      = 40788,
    NPC_OZUMAT                  = 44566,
    NPC_OZUMAT_VEHICLE          = 44581,
    NPC_OZUMAT_ADD_SPAWNER      = 44656,
    NPC_OZUMAT_VEHICLE_BIG      = 45030,
    NPC_NEPTULON                = 40792,
    NPC_CAPTAIN_TAYLOR          = 50270,
    NPC_LEGIONNAIRE_NAZGRIM     = 50272,

    GO_COMMANDER_ULTHOK_DOOR    = 204338,
    GO_CORALES                  = 205542,
    GO_LADY_NAZJAR_DOOR         = 204339,
    GO_ERUNAK_STONESPEAKER_DOOR = 204340,
    GO_OZUMAT_DOOR              = 204341,
    GO_NEPTULON_CACHE           = 205216,
    GO_NEPTULON_CACHE_H         = 207973,
    GO_TENTACLE_RIGHT           = 208302,
    GO_TENTACLE_LEFT            = 208301,
    GO_CONTROL_SYSTEM           = 203199,
    GO_INVISIBLE_DOOR_1         = 207997,
    GO_INVISIBLE_DOOR_2         = 207998,
};

enum Data
{
    DATA_LADY_NAZJAR            = 0,
    DATA_COMMANDER_ULTHOK       = 1,
    DATA_MINDBENDER_GHURSHA     = 2,
    DATA_OZUMAT                 = 3,
    DATA_ERUNAK_STONESPEAKER    = 4,
    DATA_NEPTULON               = 5,
    DATA_CORALES                = 6,
    DATA_LADY_NAZJAR_EVENT      = 7,
    DATA_COMMANDER_ULTHOK_EVENT = 8,
    DATA_NEPTULON_EVENT         = 9,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_throne_of_the_tides"))
                return new AI(creature);
    return NULL;
}

#endif
