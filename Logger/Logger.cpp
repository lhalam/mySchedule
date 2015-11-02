#include "Logger.h"
#include <cstdlib>

void Logger::Log(const LogMessage& msg)
{
	/*
	if(_msgLevel < ReportingLevel)
	return;
	*/
	ofstream fout("Log.txt", ios::app);
	if(!fout.is_open())
		throw exception("Cannot open file for writing!");

	fout << msg;
	fout.close();
}

Logger* Logger::FindInRegistry(const char* name)
{
	Logger* res = NULL;
	auto it = registry.find(name);
	if (it != registry.end())
	{
		res = (*it).second;
	}
	return res;
}

Logger* Logger::Instance(const char* name)
{
	if(!instanceUnique)
	{
		Logger* found = FindInRegistry(name);
		if (!found)
		{
			instanceUnique = new Logger;
			Register(name, instanceUnique);
		}
		else
		{
			instanceUnique = found;
		}
	}
	return instanceUnique;
}

void Logger::Register(const char* name, Logger* lg)
{
	auto it = registry.find(name);
	if (it == registry.end())
	{
		registry[name] = lg;
	}
}