#pragma once

#include "DAO.h"
#include "Group.h"

class DAOGroup : public DAO
{
public:
	DAOGroup(MySQLAccess conn);

	//Getters

	Entity * getById(unsigned id) const;
	Group getByName(string name) const;

	// Setters

	void addGroup(const Group& group) const;
	void updateName(const Group& group, string newName) const;
};
