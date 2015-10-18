#pragma once

#include "DAO.h"
#include "User.h"

class DAOUser : public DAO
{
public:
	//Getters

	virtual Entity * getById(BaseConnection connection, unsigned id) const;
	vector<User> getByName(BaseConnection connection, string name) const;
	vector<User> getBySurname(BaseConnection connection, string name) const;
	vector<User> getByFullName(BaseConnection connection, string name, string surname) const;
	vector<User> getByGroup(BaseConnection connection, string group) const;

	//Setters

	void addUser(BaseConnection connection, const User& user) const;
	void updateName(BaseConnection connection, const User& user, string newName) const;
	void updateSurname(BaseConnection connection, const User& user, string newSurName) const;
	void updateRole(BaseConnection connection, const User& user, int newRole) const;
};
