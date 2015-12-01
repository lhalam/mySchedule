#include "Logger.h"

ServerLogger* ServerLogger::Instance()
{
	if (!slogger_instance)
	{
		slogger_instance = new ServerLogger;
	}
	return slogger_instance;
}

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

DBLogger* DBLogger::Instance()
{
	if (!dblogger_instance)
	{
		dblogger_instance = new DBLogger;
	}
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

ConfigLogger* ConfigLogger::Instance()
{
	if (!clogger_instance)
	{
		clogger_instance = new ConfigLogger;
	}
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
