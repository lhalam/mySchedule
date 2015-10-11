#include "LogMessage.h"

LogMessage::LogMessage() :
_status(""),
_method("")
{
}

LogMessage::LogMessage(string status, string method) :
_status(status),
_method(method)
{
}

LogMessage::LogMessage(const LogMessage & obj) :
_status(obj._status),
_method(obj._method)
{
}

ostream & operator<< (ostream & stream, const LogMessage & obj)
{
	stream << '[' << __TIMESTAMP__ << ']' << '\t' 
		<< obj._status << '\t' << '\t' 
		<< obj._method << endl;
	return stream;
}