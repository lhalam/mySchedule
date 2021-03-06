#pragma once

#include "DAO.h"
#include "User.h"

class DAOUser : public DAO
{
public:
	static const DAOUser * getInstance();

	//Getters

	virtual User * getById(MySQLAccess *connection, unsigned id) const;
	User getByLogin(MySQLAccess *connection, string login) const;
	vector<User> getByName(MySQLAccess *connection, string name) const;
	vector<User> getBySurname(MySQLAccess *connection, string name) const;
	vector<User> getByFullName(MySQLAccess *connection, string name, string surname) const;
	vector<User> getByRole(MySQLAccess *connection, int roleID) const;
	vector<User> getByGroup(MySQLAccess *connection, int groupID) const;

	//Setters

	void add(MySQLAccess *connection, const User& user) const;
	void remove(MySQLAccess *connection, const User& user) const;

	void updateLogin(MySQLAccess *connection, const User& user, string newLogin) const;
	void updateName(MySQLAccess *connection, const User& user, string newName) const;
	void updateSurname(MySQLAccess *connection, const User& user, string newSurName) const;
	void updateRole(MySQLAccess *connection, const User& user, int newRole) const;
	void updateGroup(MySQLAccess *connection, const User& user, int newGroup) const;

private:
	DAOUser() { }

	DAOUser(const DAOUser& dao) = delete;
	DAOUser& operator=(const DAOUser& dao) = delete;
};
