#include "Logger.h"

ServerLogger* ServerLogger::Instance()
{
	if (!slogger_instance)
	{
		slogger_instance = new ServerLogger;
		//Register("ServerLogger", slogger_instance);
	}
	/*else
	{
		slogger_instance = dynamic_cast<ServerLogger*>(registry.at("ServerLogger"));
	}*/
	return slogger_instance;
}

//void ServerLogger::Register(string name, ServerLogger* lg)
//{
//	auto it = registry.find(name);
//	if (it == registry.end())
//	{
//		registry[name] = lg;
//	}
//}

void ServerLogger::Log(const LogMessage& msg)
{
	if (msg.getLogLevel() < Logger::ReportingLevel)
		return;
	ofstream fout("Logs.log", ios::app);
	if (!fout.is_open())
	{
		throw exception("Cannot open file for writing.");
	}
	fout << "[ServerLogger]" << endl
		<< msg;
	fout.close();

	fout.open("ServerLog.log", ios::app);
	if (!fout.is_open())
	{
		throw exception("Cannot open file for writing.");
	}
	fout << msg;
	fout.close();
}

//void DBLogger::Register(string name, DBLogger* lg)
//{
//	auto it = registry.find(name);
//	if (it == registry.end())
//	{
//		registry[name] = lg;
//	}
//}

DBLogger* DBLogger::Instance()
{
	if (!dblogger_instance)
	{
		dblogger_instance = new DBLogger;
		//Register("DBLogger", dblogger_instance);
	}
	/*else
	{
		dblogger_instance = dynamic_cast<DBLogger*>(registry.at("DBLogger"));
	}*/
	return dblogger_instance;
}

void DBLogger::Log(const LogMessage& msg) 
{
	if (msg.getLogLevel() < Logger::ReportingLevel)
		return;

	ofstream fout("Logs.log", ios::app);
	if (!fout.is_open())
	{
		throw exception("Cannot open file for writing.");
	}
	fout << "[DatabaseLogger]" << endl
		<< msg;
	fout.close();

	fout.open("DatabaseLog.log", ios::app);
	if (!fout.is_open())
	{
		throw exception("Cannot open file for writing.");
	}
	fout << msg;
	fout.close();
}
//
//void ConfigLogger::Register(string name, ConfigLogger* lg)
//{
//	auto it = registry.find(name);
//	if (it == registry.end())
//	{
//		registry[name] = lg;
//	}
//}
//
ConfigLogger* ConfigLogger::Instance()
{
	if (!clogger_instance)
	{
		clogger_instance = new ConfigLogger;
		//Register("ConfigLogger", clogger_instance);
	}
	/*else
	{
		clogger_instance = dynamic_cast<ConfigLogger*>(registry.at("ConfigLogger"));
	}*/
	return clogger_instance;
}


void ConfigLogger::Log(const LogMessage& msg)
{
	if (msg.getLogLevel() < Logger::ReportingLevel)
		return;

	ofstream fout("Logs.log", ios::app);
	if (!fout.is_open())
	{
		throw exception("Cannot open file for writing.");
	}
	fout << "[ConfigLogger]" << endl
		<< msg;
	fout.close();

	fout.open("ConfigLog.log", ios::app);
	if (!fout.is_open())
	{
		throw exception("Cannot open file for writing.");
	}
	fout << msg;
	fout.close();
}
