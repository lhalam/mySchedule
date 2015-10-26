#include "DAOEvent.h"

const DAOEvent& DAOEvent::getInstance()
{
	static DAOEvent instance;
	return instance;
}

Entity * DAOEvent::getById(MySQLAccess& connection, unsigned id) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select (id, name) from event where id='" + std::to_string(id) + "'");

		Event *_event = new Event(res);
		delete res;
		return _event;
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

Event DAOEvent::getByName(MySQLAccess& connection, string name) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select (id, name) from event where name='" + name + "'");

		Event _event(res);
		delete res;
		return _event;
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

void DAOEvent::add(MySQLAccess& connection, const Event& _event) const
{
	try
	{
		connection.execute("INSERT INTO event (name) VALUES ('" + _event.getName() + "')");
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

void DAOEvent::updateName(MySQLAccess& connection, const Event& _event, string newName) const
{
	try
	{
		connection.execute("UPDATE event SET name='" + newName + "' WHERE id=" + std::to_string(_event.getID()));
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
