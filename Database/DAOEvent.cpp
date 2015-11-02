#include "DAOEvent.h"

const DAOEvent * DAOEvent::getInstance()
{
	static DAOEvent instance;
	return &instance;
}

Entity * DAOEvent::getById(MySQLAccess *connection, unsigned id) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"select * from `event` where id=" + to_string(id));
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
			"select * from `event` where name='" + name + "'");
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
		connection->execute("insert into `event` (name) values ('" +
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
		connection->execute("delete from `event` "
			"where id=" + to_string(e.getID()));
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
		connection->execute("update `event` set name='" + newName + "' "
			"where id=" + to_string(e.getID()));
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
