#pragma once

#include "DAO.h"
#include "Group.h"

class DAOGroup : public DAO
{
public:
	static const DAOGroup& getInstance();

	//Getters

	virtual Entity * getById(MySQLAccess& connection, unsigned id) const;
	Group getByName(MySQLAccess& connection, string name) const;

	// Setters

	void add(MySQLAccess& connection, const Group& group) const;
	void updateName(MySQLAccess& connection, const Group& group, string newName) const;

private:
	DAOGroup() { }

	DAOGroup(const DAOGroup& dao) = delete;
	DAOGroup& operator=(const DAOGroup& dao) = delete;
};
