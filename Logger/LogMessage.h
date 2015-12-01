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
	LogMessage(string status, string method, LogLevel = logError); //server
	LogMessage(string filename, unsigned line, string method, string err_code, string mysql_err_code, string sqlstate); //sql
	LogMessage(string filename, unsigned line, string status, string method); //config
	LogMessage(const LogMessage&);

	LogLevel getLogLevel() const;

	friend ostream & operator<< (ostream &, const LogMessage&);
private:
	string _status;
	string _method;
	LogLevel _llevel;
};