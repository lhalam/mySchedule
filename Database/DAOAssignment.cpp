#include "DAOAssignment.h"

const DAOAssignment * DAOAssignment::getInstance()
{
	static DAOAssignment instance;
	return &instance;
}

//Getters

Entity * DAOAssignment::getById(MySQLAccess *connection, unsigned id) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `assignment` WHERE id=" + to_string(id));
		res->next();

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

Assignment DAOAssignment::getByName(MySQLAccess *connection, string name) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `assignment` WHERE name='" + name + "'");
		res->next();

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

vector<Assignment> DAOAssignment::getByGroup(MySQLAccess *connection, int groupID) const
{
	vector<Assignment> result;
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `assignment` WHERE group_id=" + to_string(groupID) + " "
			"ORDER BY id");

		while (res->next())
		{
			Assignment a(connection, res);
			result.push_back(a);
		}
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::getByGroup() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByGroup() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return result;
}

vector<Assignment> DAOAssignment::getByLecturer(MySQLAccess *connection, int lecturerID) const
{
	vector<Assignment> result;
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `assignment` WHERE user_id=" + to_string(lecturerID) + " "
			"ORDER BY id");

		while (res->next())
		{
			Assignment a(connection, res);
			result.push_back(a);
		}
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::getByLecturer() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByLecturer() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return result;
}

//Setters

void DAOAssignment::add(MySQLAccess *connection, const Assignment& assignment) const
{
	try
	{
		connection->execute("INSERT INTO `assignment` (name, task, user_id, group_id) "
			"VALUES ('" + assignment.getSubject() + "', '" + assignment.getTask()
			+ "', " + to_string(assignment.getLecturer().getID()) + ", " +
			to_string(assignment.getGroup().getID()) + "')");
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

void DAOAssignment::remove(MySQLAccess *connection, const Assignment& assignment) const
{
	try
	{
		connection->execute("DELETE FROM `assignment` "
			"WHERE id=" + to_string(assignment.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::remove() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::remove() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOAssignment::updateName(MySQLAccess *connection, const Assignment& assignment, string newName) const
{
	try
	{
		connection->execute("UPDATE `assignment` SET name='" + newName + "' "
			"WHERE id=" + to_string(assignment.getID()));
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

void DAOAssignment::updateTask(MySQLAccess *connection, const Assignment& assignment, string newTask) const
{
	try
	{
		connection->execute("UPDATE `assignment` SET task='" + newTask + "' "
			"WHERE id=" + to_string(assignment.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::updateTask() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::updateTask() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOAssignment::updateGroup(MySQLAccess *connection, const Assignment& assignment, int newGroup) const
{
	try
	{
		connection->execute("UPDATE assignment SET group_id=" + to_string(newGroup) + " "
			"WHERE id=" + to_string(assignment.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::updateGroup() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::updateGroup() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOAssignment::updateLecturer(MySQLAccess *connection, const Assignment& assignment, int newLecturer) const
{
	try
	{
		connection->execute("UPDATE assignment SET user_id=" +
			to_string(newLecturer) + " WHERE id=" +
			to_string(assignment.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOAssignment::updateLecturer() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOAssignment::updateLecturer() occured.\n";
		cerr << exp.what() << endl;
	}
}
