#pragma once
#include "LogMessage.h"
#include <fstream>

class Logger
{
public:
	//log given message
	void Log(const LogMessage& msg);

	//General reporting level
	static LogLevel ReportingLevel;

	static Logger* Instance();

private:
	//internal message level
	LogLevel _msgLevel;
	static Logger* instanceUnique;

	//default constructors and "=" operator in private
	//to keep logger unique
	Logger() {}
	Logger(const Logger&) {}
	Logger& operator=(Logger const&) {}

	virtual ~Logger()
	{
		delete instanceUnique;
	}
};

