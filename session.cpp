#include <iostream>
#include <string>
#include <memory>
using namespace std;

class Session
{
private:
	string login;
	string password;

public:
	Session()
	{
			login = "no login";
			password = "no password";
	}

	Session(string _login, string _password)
	{
					login = _login;
					password = _password;
	}
};

class SessionFactory
{
public:
	static unique_ptr<Session> GetInstance()
	{
		if(session == nullptr)
		{
			session = new Session();
		}
		return unique_ptr<Session>(session);
	}

private:
	static Session* session;
};
