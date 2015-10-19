#pragma once

#include "DAO.h"
#include "Assignment.h"

class DAOAssignment : public DAO
{
public:
	static const DAOAssignment& getInstance();

	//Getters

	virtual Entity * getById(MySQLAccess& connection, unsigned id) const;
	Assignment getByName(MySQLAccess& connection, string name) const;

	//Setters

	void add(MySQLAccess& connection, const Assignment& assignment) const;
	void updateName(MySQLAccess& connection, const Assignment& assignment, string newName) const;

private:
	DAOAssignment() { }

	DAOAssignment(const DAOAssignment& dao) = delete;
	DAOAssignment& operator=(const DAOAssignment& dao) = delete;
};
