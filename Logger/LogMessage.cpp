#include "LogMessage.h"

string getCurrentTime()
{
	system_clock::time_point today = system_clock::now();

	time_t time;
	char buffer[80];

	time = system_clock::to_time_t(today);
	ctime_s(buffer, 80, &time);
	return buffer;
}

LogMessage::LogMessage() :
_status(""),
_method(""),
_llevel(LogLevel::logError)
{
}

LogMessage::LogMessage(string status, string method, LogLevel level) :
_status(status),
_method(method),
_llevel(level)
{
}

LogMessage::LogMessage(const LogMessage & obj) :
_status(obj._status),
_method(obj._method),
_llevel(obj._llevel)
{
}

LogLevel LogMessage::getLogLevel() const
{
	return this->_llevel;
}

ostream & operator<< (ostream & stream, const LogMessage & obj)
{
	stream << getCurrentTime() << '\t'
		<< obj._status << '\t' << '\t' 
		<< obj._method << endl;
	return stream;
}