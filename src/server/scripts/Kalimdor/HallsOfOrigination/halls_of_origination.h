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

#ifndef DEF_HALLS_OF_ORIGINATION_H
#define DEF_HALLS_OF_ORIGINATION_H

enum Data
{
    DATA_TEMPLE_GUARDIAN_ANHUUR,
    DATA_EARTHRAGER_PTAH,
    DATA_ANRAPHET,
    DATA_ISISET,
    DATA_AMMUNAE,
    DATA_SETESH,
    DATA_RAJH,
    DATA_FLAME_WARDEN,
    DATA_WATER_WARDEN,
    DATA_EARTH_WARDEN,
    DATA_AIR_WARDEN,
    DATA_BRANN,
    DATA_WARDENS,
    DATA_ANRAPHET_ENTRANCE_DOOR,
    DATA_ANRAPHET_BOSS_DOOR,
    DATA_TEAM_IN_INSTANCE,
};

enum GameObjectIds
{
    GO_ORIGINATION_ELEVATOR         = 207547,
    GO_LARGE_STONE_OBELISK          = 207410,
    GO_ANHUUR_BRIDGE                = 206506,
    GO_ANHUUR_ELEVATOR              = 207725,
    GO_DOOR_ULDUM_14                = 202306,
    GO_DOOR_ULDUM_15                = 202307,
    GO_VAULT_OF_LIGHTS_ENTR_DOOR    = 202313,
    GO_VAULT_OF_LIGHTS_BOSS_DOOR    = 202314,
};

enum CreatureIds
{
    NPC_TEMPLE_GUARDIAN_ANHUUR = 39425,
    NPC_EARTHRAGER_PTAH        = 39428,
    NPC_ANRAPHET               = 39788,
    NPC_ISISET                 = 39587,
    NPC_AMMUNAE                = 39731,
    NPC_SETESH                 = 39732,
    NPC_RAJH                   = 39378,

    NPC_BLISTERING_SCARAB      = 40310,
    //NPC_BLOODPETAL_BLOSSOM   = 40620,
    NPC_DUSTBONE_TORMENTOR     = 40311,
    //NPC_DUSTBONE_HORROR      = 40787,
    //NPC_JEWELED_SCARAB       = 40458,
    NPC_EARTH_WARDEN           = 39801,
    NPC_FLAME_WARDEN           = 39800,
    NPC_FLUX_ANIMATOR          = 40033,
    NPC_LIFEWARDEN_NYMPH       = 40715,
    NPC_LIVING_VINE            = 40668,
    NPC_SPATIAL_ANOMALY        = 40170,
    NPC_TEMPLE_SWIFTSTALKER    = 48139,
    NPC_TEMPLE_SHADOWLANCER    = 48141,
    NPC_TEMPLE_RUNECASTER      = 48140,
    NPC_TEMPLE_FIRESHAPER      = 48143,
    NPC_VENOMOUS_SKITTERER     = 39440,
    NPC_WATER_WARDEN           = 39802,
    NPC_AIR_WARDEN             = 39803,
    NPC_BRANN_BRONZEBEARD      = 39908,
    NPC_SEARING_LIGHT          = 40283,
    NPC_BEETLE_STALKER         = 40459,
    NPC_ALPHA_BEAM             = 41144,
    NPC_OMEGA_STANCE           = 41194,
};

enum Achievements
{
    SPELL_FASTER_THAN_LIGHT       = 94067,
    EVENT_FASTER_THAN_LIGHT       = 24212,
    ACHIEV_STRAW_THAT_BROKE_CAMEL = 5294,
};

enum Worldstates
{
    WORLDSTATE_I_HATE_THAT_SONG               = 8782,
    WORLDSTATE_FASTER_THAN_THE_SPEED_OF_LIGHT = 8804,
    WORLDSTATE_SUN_OF_A                       = 8783,
};

template<class AI>
CreatureAI* GetInstanceAI(Creature* creature)
{
    if (InstanceMap* instance = creature->GetMap()->ToInstanceMap())
        if (instance->GetInstanceScript())
            if (instance->GetScriptId() == sObjectMgr->GetScriptId("instance_halls_of_origination"))
                return new AI(creature);
    return NULL;
}

#endif