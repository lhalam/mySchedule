#pragma once
#include "LogMessage.h"
#include <iostream>
#include <fstream>
#include <map>

class Logger
{
public:
	virtual void Log(const LogMessage& msg) = 0;

	//General reporting level
	static LogLevel ReportingLevel;

protected:
	Logger() {}
	Logger(const Logger&) = delete;
	Logger& operator=(Logger const&) = delete;

	virtual ~Logger() {}
};

class ServerLogger : public Logger
{
private:
	ServerLogger() : Logger() {}
	ServerLogger(const ServerLogger& slog) = delete;
	ServerLogger& operator=(const ServerLogger& slog) = delete;

	static ServerLogger* slogger_instance;
public:
	static ServerLogger* Instance();
	virtual void Log(const LogMessage& msg);
	virtual ~ServerLogger()
	{
		delete slogger_instance;
	}
};

class DBLogger : public Logger
{
private:
	DBLogger() : Logger() {}
	DBLogger(const DBLogger& slog) = delete;
	DBLogger& operator=(const DBLogger& slog) = delete;

	static DBLogger* dblogger_instance;
public:
	static DBLogger* Instance();
	virtual void Log(const LogMessage& msg);

	virtual ~DBLogger()
	{
		delete dblogger_instance;
	}
};

class ConfigLogger : public Logger
{
private:
	ConfigLogger() : Logger() {}
	ConfigLogger(const ConfigLogger& slog) = delete;
	ConfigLogger& operator=(const ConfigLogger& slog) = delete;

	static ConfigLogger* clogger_instance;
public:
	static ConfigLogger* Instance();
	virtual void Log(const LogMessage& msg);
	virtual ~ConfigLogger()
	{
		delete clogger_instance;
	}
};