#include "Logger.h"

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

Logger* Logger::Instance()
{
	if(!instanceUnique)
	{
		instanceUnique = new Logger;
	}
	return instanceUnique;
}