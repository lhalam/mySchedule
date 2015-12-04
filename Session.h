#pragma once
#include "Database\User.h"
#include <exception>
#include <map>

class Session
{ 
	const User* currentUser;
	bool islogged;
	static map<const string, const User> session_registry;
	static const User* findInRegistry(const string);

	Session();
	Session(const User&) = delete;
	Session(const Session&) = delete;

	~Session();
public:
	static Session* getInstance();
	const User* getCurrentUser() const;
	void logIn(const string, const string);
	void logOut();
	static void registerUser(const User);
};