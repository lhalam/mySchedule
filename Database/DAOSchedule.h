#pragma once

#include "DAO.h"
#include "Schedule.h"

class DAOSchedule : public DAO
{
public:
	DAOSchedule(string HOST, string USER, string PASSWORD, string DB) :
		DAO(HOST, USER, PASSWORD, DB)
	{
	}

	//Getters

	//Setters

};
