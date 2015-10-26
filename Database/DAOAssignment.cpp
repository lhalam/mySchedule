#include "DAOAssignment.h"

const DAOAssignment& DAOAssignment::getInstance()
{
	static DAOAssignment instance;
	return instance;
}

//Getters

Entity * DAOAssignment::getById(MySQLAccess& connection, unsigned id) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select * from assignment where id=" + std::to_string(id));

		Assignment *assignment = new Assignment(connection, res);
		delete res;
		return assignment;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return nullptr;
}

Assignment DAOAssignment::getByName(MySQLAccess& connection, string name) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select * from assignment where name='" + name + "'");

		Assignment assignment(connection, res);
		delete res;
		return assignment;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
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
