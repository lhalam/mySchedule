#pragma once

#include "DAO.h"
#include "Group.h"

class DAOGroup : public DAO
{
public:
	//Getters

	Entity * getById(MySQLAccess connection, unsigned id) const;
	Group getByName(MySQLAccess connection, string name) const;

	// Setters

	void addGroup(MySQLAccess connection, const Group& group) const;
	void updateName(MySQLAccess connection, const Group& group, string newName) const;
};
