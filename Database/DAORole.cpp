#include "DAORole.h"

const DAORole& DAORole::getInstance()
{
	static DAORole instance;
	return instance;
}

Entity * DAORole::getById(MySQLAccess& connection, unsigned id) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select (id, name) from role where id='" + std::to_string(id) + "'");

		Role *role = new Role(res);
		delete res;
		return role;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAORole::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAORole::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return nullptr;
}

Role DAORole::getByName(MySQLAccess& connection, string name) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection.executeQuery(
			"select (id, name) from role where name='" + name + "'");

		Role role(res);
		delete res;
		return role;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAORole::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAORole::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return Role();
}

void DAORole::add(MySQLAccess& connection, const Role& role) const
{
	try
	{
		connection.execute("INSERT INTO role (name) VALUES ('" + role.getName() + "')");
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAORole::add() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAORole::add() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAORole::updateName(MySQLAccess& connection, const Role& role, string newName) const
{
	try
	{
		connection.execute("UPDATE role SET name='" + newName + "' WHERE id=" + std::to_string(role.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAORole::updateName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAORole::updateName() occured.\n";
		cerr << exp.what() << endl;
	}
}
