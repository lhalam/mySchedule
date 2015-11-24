#pragma once
#include "LogMessage.h"
#include <fstream>
#include <map>

class Logger;

static map<const char*, Logger*> registry;

class Logger
{
public:
	//log given message
	void Log(const LogMessage& msg);

	//General reporting level
	static LogLevel ReportingLevel;

	static Logger* Instance(const char* name);
	static void Register(const char* name, Logger* lg);
protected:
	static Logger* FindInRegistry(const char* name);
private:
	static Logger* instanceUnique;
	//default constructors and "=" operator in private
	//to keep logger unique
	Logger() {}
	Logger(const Logger&) = delete;
	Logger& operator=(Logger const&) = delete;

	virtual ~Logger()
	{
		delete instanceUnique;
	}
};