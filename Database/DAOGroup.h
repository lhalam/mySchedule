#pragma once

#include "DAO.h"
#include "Group.h"

class DAOGroup : public DAO
{
public:
	//Getters

	Entity * getById(BaseConnection connection, unsigned id) const;
	Group getByName(BaseConnection connection, string name) const;

	// Setters

	void addGroup(BaseConnection connection, const Group& group) const;
	void updateName(BaseConnection connection, const Group& group, string newName) const;
};
