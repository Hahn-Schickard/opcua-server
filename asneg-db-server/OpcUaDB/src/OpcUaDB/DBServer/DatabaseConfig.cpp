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

#include "OpcUaStackCore/Base/Log.h"
#include "OpcUaDB/DBServer/DatabaseConfig.h"

using namespace OpcUaStackCore;

namespace OpcUaDB
{

	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	//
	// class DatabaseConfig
	//
	// ------------------------------------------------------------------------
	// ------------------------------------------------------------------------
	DatabaseConfig::DatabaseConfig(void)
	: dsnName_("")
	, userName_("")
	, password_("")
	{
	}

	DatabaseConfig::~DatabaseConfig(void)
	{
	}

	std::string
	DatabaseConfig::dsnName(void)
	{
		return dsnName_;
	}

	std::string&
	DatabaseConfig::userName(void)
	{
		return userName_;
	}

	std::string&
	DatabaseConfig::password(void)
	{
		return password_;
	}

	bool
	DatabaseConfig::decode(Config& config)
	{
		bool success;

		// get database name
		success = config.getConfigParameter("DsnName", dsnName_);
		if (!success) {
			Log(Error, "element missing in config file")
				.parameter("Element", "DBModel.Database.Name")
				.parameter("ConfigFileName", config.configFileName());
			return false;
		}

		// get user name
		config.getConfigParameter("UserName", userName_, "");

		// get password
		config.getConfigParameter("Password", password_, "");


		return true;
	}

}
