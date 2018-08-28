/*
 * --- License -------------------------------------------------------------- *
 */

/*
 * Copyright 2017 NIKI 4.0 project team
 *
 * NIKI 4.0 was financed by the Baden-Württemberg Stiftung gGmbH (www.bwstiftung.de).
 * Project partners are FZI Forschungszentrum Informatik am Karlsruher
 * Institut für Technologie (www.fzi.de), Hahn-Schickard-Gesellschaft
 * für angewandte Forschung e.V. (www.hahn-schickard.de) and
 * Hochschule Offenburg (www.hs-offenburg.de).
 * This file was developed by the Institute of reliable Embedded Systems
 * and Communication Electronics
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/


#ifndef OPCUADBSERVER_H_
#define OPCUADBSERVER_H_

#include "OpcUaDB/DBServer/DBServer.h"
#include "OpcUaDB/odbc/Connection.h"
#include "opcuaDatabaseConfig.h"
#include "opcuaDbModelConfig.h"


namespace OpcUaPluginDB
{

class DbServer
{
public:
  typedef std::map<std::string, std::string> dataMap;

  DbServer(void);

  ~DbServer(void);

  bool startup(void);

  void dbModelConfig(OpcuaDBModelConfig* dbModelConfig);

  OpcUaDB::DBServer& DBServer(void);

  bool shutdown(void);


  bool createDatabase(std::string& dbName);

  bool createDatabaseTable(std::string& dbTableName);

  bool writeDataToDatabase(std::string& dbTableName
    , OpcUaNodeId& nodeId
    , OpcUaDataValue& dataValue);

  /**
   * \brief   reads history data values of a node from database.
   *
   * \param    nodeId          nodeId of node to read history data.
   * \param    startTime       start time to read history data.
   * \param    stopTime        end time to read history data.
   * \param    dataValues      Vector to store results.
   */
  bool readDataFromDatabase(std::string& dbTableName
    , OpcUaNodeId& nodeId
    , OpcUaDateTime startTime
    , OpcUaDateTime stopTime
    , OpcUaDataValue::Vec& dataValues);

  bool connectDatabase();

  bool disconnectDatabase();

  bool isConnectedDatabase();


private:

  bool execSQLDirect(const std::string& sqlQuery);

  /**
    * \brief   executes SQL query.
    *
    * \param    sqlQuery     query to execute.
    * \param    dataValues   Vector to store dataValue result.
    */
  bool execSQLDirect(const std::string& sqlQuery, OpcUaDataValue::Vec& dataValues);

  /**
    * \brief   parses the SQL query result.
    *
    * \param    inputString     SQL dataValue query result.
    * \param    dataStrMap      Map to store parsed SQL query result.
    */
  bool parseDataValue(std::string& inputString, dataMap& dataStrMap);

  /**
    * \brief   creates resultSets from database tables.
    *
    * \param    resultSet       stored database table result.
    * \param    statusCode      status code.
    * \param    header          header of database table.
    * \param    dataVec         Vector to store results.
    */
  bool createResultSet(OpcUaDB::ResultSet& resultSet
      , OpcUaDataValue::SPtr& statusCode
      , OpcUaDataValue::SPtr& header
      , OpcUaDataValue::Vec& dataVec);


  OpcUaDB::DBServer dbServer_;
  OpcuaDBModelConfig* dbModelConfig_;
  OpcUaDB::Connection connection;
  // Not the cleanest sollution, but asneg does not provide a connection check
  bool databaseConected = false; 
};

} /* namespace OpcUaPluginDB */

#endif /* OPCUADBSERVER_H_ */
