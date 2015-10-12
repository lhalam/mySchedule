#include "LogMessage.h"

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

ostream & operator<< (ostream & stream, const LogMessage & obj)
{
	stream << '[' << __TIMESTAMP__ << ']' << '\t' 
		<< obj._status << '\t' << '\t' 
		<< obj._method << endl;
	return stream;
}