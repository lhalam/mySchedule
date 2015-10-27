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
	vector<Assignment> getByGroup(MySQLAccess& connection, int groupID) const;
	vector<Assignment> getByLecturer(MySQLAccess& connection, int lecturerID) const;

	//Setters

	void add(MySQLAccess& connection, const Assignment& assignment) const;
	void updateName(MySQLAccess& connection, const Assignment& assignment, string newName) const;
	void updateTask(MySQLAccess& connection, const Assignment& assignment, string newTask) const;
	void updateGroup(MySQLAccess& connection, const Assignment& assignment, int newGroup) const;
	void updateLecturer(MySQLAccess& connection, const Assignment& assignment, int newLecturer) const;

private:
	DAOAssignment() { }

	DAOAssignment(const DAOAssignment& dao) = delete;
	DAOAssignment& operator=(const DAOAssignment& dao) = delete;
};
