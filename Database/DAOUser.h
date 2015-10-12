#pragma once

#include "DAO.h"
#include "User.h"

class DAOUser : public DAO
{
public:
	DAOUser(MySQLAccess conn);

	//Getters

	virtual Entity * getById(unsigned id) const;
	vector<User> getByName(string name) const;
	vector<User> getBySurname(string name) const;
	vector<User> getByFullName(string name, string surname) const;
	vector<User> getByGroup(string group) const;

	//Setters

	void addUser(const User& user) const;
	void updateName(const User& user, string newName) const;
	void updateSurname(const User& user, string newSurName) const;
	void updateRole(const User& user, int newRole) const;
};
