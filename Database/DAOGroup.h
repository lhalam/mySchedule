#pragma once

#include "DAO.h"
#include "Group.h"

class DAOGroup : public DAO
{
public:
	DAOGroup(MySQLAccess conn);

	//Getters

	Entity getById(unsigned id) const;
	Group getByName(string name) const;

	// Setters

};
