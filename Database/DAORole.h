#pragma once

#include "DAO.h"
#include "Role.h"

class DAORole : public DAO
{
public:
	static const DAORole * getInstance();

	//Getters

	virtual Entity * getById(MySQLAccess *connection, unsigned id) const;
	Role getByName(MySQLAccess *connection, string name) const;

	//Setters

	void add(MySQLAccess *connection, const Role& role) const;
	void remove(MySQLAccess *connection, const Role& role) const;

	void updateName(MySQLAccess *connection, const Role& role, string newName) const;

private:
	DAORole() { }

	DAORole(const DAORole& dao) = delete;
	DAORole& operator=(const DAORole& dao) = delete;
};
