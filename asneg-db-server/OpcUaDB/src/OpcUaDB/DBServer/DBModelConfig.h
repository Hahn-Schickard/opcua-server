/*
   Copyright 2017 Kai Huebl (kai@huebl-sgh.de)

   Lizenziert gemäß Apache Licence Version 2.0 (die „Lizenz“); Nutzung dieser
   Datei nur in Übereinstimmung mit der Lizenz erlaubt.
   Eine Kopie der Lizenz erhalten Sie auf http://www.apache.org/licenses/LICENSE-2.0.

   Sofern nicht gemäß geltendem Recht vorgeschrieben oder schriftlich vereinbart,
   erfolgt die Bereitstellung der im Rahmen der Lizenz verbreiteten Software OHNE
   GEWÄHR ODER VORBEHALTE – ganz gleich, ob ausdrücklich oder stillschweigend.

   Informationen über die jeweiligen Bedingungen für Genehmigungen und Einschränkungen
   im Rahmen der Lizenz finden Sie in der Lizenz.

   Autor: Kai Huebl (kai@huebl-sgh.de)
 */

#ifndef __OpcUaDB_DBModelConfig_h__
#define __OpcUaDB_DBModelConfig_h__

#include "OpcUaStackCore/Base/ConfigXmlManager.h"
#include "OpcUaDB/DBServer/DatabaseConfig.h"
#include "OpcUaDB/DBServer/OpcUaAccessConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaDB
{

	class DBModelConfig
	{
	  public:
		DBModelConfig(void);
		~DBModelConfig(void);

		DatabaseConfig& databaseConfig(void);
		OpcUaAccessConfig& opcUaAccessConfig(void);

		bool decode(Config& config);

	  private:
		DatabaseConfig databaseConfig_;
		OpcUaAccessConfig opcUaAccessConfig_;
	};

}

#endif
