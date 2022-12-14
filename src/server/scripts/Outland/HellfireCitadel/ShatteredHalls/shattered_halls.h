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

#ifndef DEF_SHATTERED_H
#define DEF_SHATTERED_H

uint32 const EncounterCount          = 3;

enum DataTypes
{
    DATA_NETHEKURSE                  = 1,
    DATA_OMROGG                      = 2,
    DATA_KARGATH                     = 3
};

enum CreatureIds
{
    NPC_GRAND_WARLOCK_NETHEKURSE = 16807,

    // Alliance
    NPC_GUNNY                    = 54934,
    NPC_ADVANCE_SCOUT_CHADWICK   = 54933,
    NPC_HONOR_HOLD_ARCHER        = 54935,
    NPC_HONOR_HOLD_RECON         = 57907,

    // Horde
    NPC_CAZAREZ                  = 54932,
    NPC_STONE_GUARD_STOKTON      = 54931,
    NPC_THRALLMAR_SCRYER         = 57908,
    NPC_THRALLMAR_INVADER        = 57909,
};

enum GameobjectIds
{
    GO_GRAND_WARLOCK_CHAMBER_DOOR_1  = 182539,
    GO_GRAND_WARLOCK_CHAMBER_DOOR_2  = 182540
};

#endif
