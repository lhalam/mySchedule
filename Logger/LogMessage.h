#pragma once
#include <string>
using namespace std;

class LogMessage
{
public:
	LogMessage();
	LogMessage(string, string);
	LogMessage(const LogMessage&);

	friend ostream & operator<< (ostream &, const LogMessage&);
private:
	string _status;
	string _method;
};