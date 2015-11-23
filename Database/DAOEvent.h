#pragma once

#include "DAO.h"
#include "Event.h"

class DAOEvent : public DAO
{
public:
	static const DAOEvent * getInstance();

	//Getters

	virtual Event * getById(MySQLAccess *connection, unsigned id) const;
	Event getByName(MySQLAccess *connection, string name) const;

	//Setters

	void add(MySQLAccess *connection, const Event& e) const;
	void remove(MySQLAccess *connection, const Event& e) const;

	void updateName(MySQLAccess *connection, const Event& e, string newName) const;

private:
	DAOEvent() { }

	DAOEvent(const DAOEvent& dao) = delete;
	DAOEvent& operator=(const DAOEvent& dao) = delete;
};