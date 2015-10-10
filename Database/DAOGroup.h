#pragma once

#include "DAO.h"
#include "Group.h"

class DAOGroup : public DAO
{
public:
	DAOGroup(string HOST, string USER, string PASSWORD, string DB) :
		DAO(HOST, USER, PASSWORD, DB)
	{
	}

	//Getters

	Entity getById(unsigned id) const;
	Group getByName(string name) const;

	// Setters

};
