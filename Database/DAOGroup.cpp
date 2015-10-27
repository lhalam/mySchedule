#include "DAOGroup.h"

const DAOGroup& DAOGroup::getInstance()
{
	static DAOGroup instance;
	return instance;
}

//Getters

Entity * DAOGroup::getById(MySQLAccess& connection, unsigned id) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select * from group where id=" + to_string(id));

		Group *group = new Group(res);
		delete res;
		return group;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOGroup::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOGroup::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return nullptr;
}

Group DAOGroup::getByName(MySQLAccess& connection, string name) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select * from group where name=" + name);

		Group group(res);
		delete res;
		return group;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOGroup::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOGroup::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
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
		connection.execute("UPDATE group SET name='" + newName + "' "
			"WHERE id=" + to_string(group.getID()));
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
