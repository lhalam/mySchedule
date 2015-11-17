#include "DAOEvent.h"

const DAOEvent * DAOEvent::getInstance()
{
	static DAOEvent instance;
	return &instance;
}

Event * DAOEvent::getById(MySQLAccess *connection, unsigned id) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `event` WHERE id=" + to_string(id));
		res->next();

		Event *e = new Event(res);
		delete res;
		return e;
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOEvent::getById() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in DAOEvent::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return nullptr;
}

Event DAOEvent::getByName(MySQLAccess *connection, string name) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `event` WHERE name='" + name + "'");
		res->next();

		Event e(res);
		delete res;
		return e;
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOEvent::getByName() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in DAOEvent::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return Event();
}

void DAOEvent::add(MySQLAccess *connection, const Event& e) const
{
	try
	{
		connection->execute("INSERT INTO `event` (name) VALUES ('" +
			e.getName() + "')");
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOEvent::add() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in DAOEvent::add() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOEvent::remove(MySQLAccess *connection, const Event& e) const
{
	try
	{
		connection->execute("DELETE FROM `event` "
			"WHERE id=" + to_string(e.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOEvent::remove() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOEvent::remove() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOEvent::updateName(MySQLAccess *connection, const Event& e, string newName) const
{
	try
	{
		connection->execute("UPDATE `event` SET name='" + newName + "' "
			"WHERE id=" + to_string(e.getID()));
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOEvent::updateName() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in DAOEvent::updateName() occured.\n";
		cerr << exp.what() << endl;
	}
}
