#pragma once

#include "DAO.h"
#include "Role.h"
#include "Entity.h"

class DAORole : public DAO
{
public:
	DAORole(MySQLAccess conn) :
		DAO(conn)
	{
	}

	//Getters

	virtual Entity * getById(unsigned id) const;
	Role getByName(string name) const;

	//Setters

};
