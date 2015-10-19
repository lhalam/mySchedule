#include "DAOAssignment.h"

const DAOAssignment& DAOAssignment::getInstance()
{
	static DAOAssignment instance;
	return instance;
}

//Getters

Entity * DAOAssignment::getById(MySQLAccess& connection, unsigned id) const
{
	try
	{
		connection.execute("select (id, name) from assignment where id=" + std::to_string(id));
		auto_ptr<ResultSet> res = connection.getResultSet();

		return new Assignment(res.get());
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	return nullptr;
}

Assignment DAOAssignment::getByName(MySQLAccess& connection, string name) const
{
	try
	{
		connection.execute("select (id, name) from assignment where name='" + name + "'");
		auto_ptr<ResultSet> res = connection.getResultSet();

		return Assignment(res.get());
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	return Assignment();
}

//Setters

void DAOAssignment::add(MySQLAccess& connection, const Assignment& assignment) const
{
	try
	{
		connection.execute("INSERT INTO assignment (name) VALUES ('" + assignment.getSubject() + "')");
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::add() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::add() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOAssignment::updateName(MySQLAccess& connection, const Assignment& assignment, string newName) const
{
	try
	{
		connection.execute("UPDATE assignment SET name='" + newName + "' WHERE id=" + std::to_string(assignment.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::updateName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::updateName() occured.\n";
		cerr << exp.what() << endl;
	}
}
