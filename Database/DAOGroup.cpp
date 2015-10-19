#include "DAOGroup.h"

const DAOGroup& DAOGroup::getInstance()
{
	static DAOGroup instance;
	return instance;
}

//Getters

Entity * DAOGroup::getById(MySQLAccess& connection, unsigned id) const
{
	try
	{
		connection.execute("select (id, name) from group where id=" + std::to_string(id));
		auto_ptr<ResultSet> res = connection.getResultSet();

		return new Group(res.get());
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOGroup::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOGroup::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	return nullptr;
}

Group DAOGroup::getByName(MySQLAccess& connection, string name) const
{
	try
	{
		connection.execute("select (id, name) from group where name=" + name);
		auto_ptr<ResultSet> res = connection.getResultSet();

		return Group(res.get());
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOGroup::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOGroup::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	return Group();
}

//Setters

void DAOGroup::add(MySQLAccess& connection, const Group& group) const
{
	try
	{
		connection.execute("INSERT INTO group (name) VALUES ('" + group.getName() + ")");
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUGroup::add() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUGroup::add() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOGroup::updateName(MySQLAccess& connection, const Group& group, string newName) const
{
	try
	{
		connection.execute("UPDATE group SET name='" + newName + "' WHERE id=" + std::to_string(group.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUGroup::updateName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOGroup::updateName() occured.\n";
		cerr << exp.what() << endl;
	}
}
