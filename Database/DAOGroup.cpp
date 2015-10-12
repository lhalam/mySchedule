#include "DAOGroup.h"

DAOGroup::DAOGroup(MySQLAccess conn) :
	DAO(conn)
{
}

//Getters

Entity * DAOGroup::getById(unsigned id) const
{
	try
	{
		connection.execute("select (id, name) from groups where id=" + std::to_string(id));
		auto_ptr<ResultSet> res = connection.getResultSet();

		return new Group(res->getInt("id"), res->getString("name"));
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

Group DAOGroup::getByName(string name) const
{
	try
	{
		connection.execute("select (id, name) from groups where name=" + name);
		auto_ptr<ResultSet> res = connection.getResultSet();

		return Group(res->getInt("id"), res->getString("name"));
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

void DAOGroup::addGroup(const Group& group) const
{
	try
	{
		connection.execute("INSERT INTO groups (name) VALUES ('" + group.getName() + ")");
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUGroup::addGroup() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUGroup::addGroup() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOGroup::updateName(const Group& group, string newName) const
{
	try
	{
		connection.execute("UPDATE groups SET name='" + newName + "' WHERE id=" + std::to_string(group.getID()));
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
