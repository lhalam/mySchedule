#pragma once
#include <string>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

string getCurrentTime();

enum LogLevel { logError, logWarning, logInfo, logDebug };

class LogMessage
{
public:
	LogMessage();
	LogMessage(string, string, LogLevel = logError);
	LogMessage(const LogMessage&);

	LogLevel getLogLevel() const;

	friend ostream & operator<< (ostream &, const LogMessage&);
private:
	string _status;
	string _method;
	LogLevel _llevel;
};