#include "Session.h"

map<const string, const User> Session::session_registry;

Session::Session() :
currentUser(nullptr),
islogged(false)
{	
}

Session::~Session()
{
	delete currentUser;
}

Session* Session::getInstance()
{
	static Session* instance = new Session();
	return instance;
}
const User* Session::getCurrentUser() const
{
	return this->currentUser;
}

void Session::logIn(const string login, const string password)
{
	if (this->islogged)
	{
		cout << "User " << this->currentUser->getLogin() << " has already logged in!" << endl;
		return;
	}

	const User* cuser = findInRegistry(login);
	if (cuser)
	{
		if (cuser->getPassword() == password)
		{
			this->currentUser = cuser;
			this->islogged = true;
		}
		else
		{
			//throw exception("Wrong password! Try again!");
		}
	}
	else
	{
		//throw exception("No user with such login exists!");
	}
}
void Session::logOut()
{
	if (!this->islogged)
	{
		//throw exception("Can not log out! You are not logged in.");
	}
	this->islogged = false;
	currentUser = nullptr;
}

void Session::registerUser(const User obj)
{
	session_registry.insert(pair<const string, const User>(obj.getLogin(), obj));
}

const User* Session::findInRegistry(const string login)
{
	const User* res;
	auto it = session_registry.find(login);
	if (it != session_registry.end())
	{
		res = &(it->second);
	}
	else
	{
		res = nullptr;
	}
	return res;
}