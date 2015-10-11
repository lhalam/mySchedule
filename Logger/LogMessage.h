#pragma once
#include <string>
using namespace std;

enum LogLevel {logError, logWarning, logInfo, logDebug};

class LogMessage
{
public:
	LogMessage();
	LogMessage(string, string, LogLevel = logError);
	LogMessage(const LogMessage&);

	friend ostream & operator<< (ostream &, const LogMessage&);
private:
	string _status;
	string _method;
	LogLevel _llevel;
};