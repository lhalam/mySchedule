#pragma once

#include "DAO.h"
#include "Event.h"

class DAOEvent : public DAO
{
public:
	static const DAOEvent& getInstance();

	//Getters

	virtual Entity * getById(MySQLAccess& connection, unsigned id) const;
	Event getByName(MySQLAccess& connection, string name) const;

	//Setters

	void add(MySQLAccess& connection, const Event& _event) const;
	void updateName(MySQLAccess& connection, const Event& _event, string newName) const;

private:
	DAOEvent() { }

	DAOEvent(const DAOEvent& dao) = delete;
	DAOEvent& operator=(const DAOEvent& dao) = delete;
};