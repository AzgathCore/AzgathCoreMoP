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

#ifndef _AZGATHEMUDATABASE_H
#define _AZGATHEMDATABASE_H

#include "DatabaseWorkerPool.h"
#include "MySQLConnection.h"

class AzgathEMUDatabaseConnection : public MySQLConnection
{
    public:
        AzgathEMUDatabaseConnection(MySQLConnectionInfo& connInfo, ConnectionFlags index)
            : MySQLConnection(connInfo, index) { }

        //- Loads database type specific prepared statements
        void DoPrepareStatements();
};

typedef DatabaseWorkerPool<AzgathEMUDatabaseConnection> AzgathEMUDatabaseWorkerPool;

enum AzgathEMUDatabaseStatements
{
    /*  Naming standard for defines:
        {DB}_{SEL/INS/UPD/DEL/REP}_{Summary of data changed}
        When updating more than one field, consider looking at the calling function
        name for a suiting suffix.
    */
    AZGATH_SEL_BATTLEPAY_COINS,
	AZGATH_UPD_BATTLEPAY_INCREMENT_COINS,
	AZGATH_UPD_BATTLEPAY_DECREMENT_COINS,
    AZGATH_UPD_BATTLEPAY_VP_COINS,
    MAX_AZGATHEMUDATABASE_STATEMENTS
};

#endif