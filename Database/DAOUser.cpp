#include "DAOUser.h"
#include "DAORole.h"

const DAOUser& DAOUser::getInstance()
{
	static DAOUser instance;
	return instance;
}

//Getters

Entity * DAOUser::getById(MySQLAccess connection, unsigned id) const
{
	try
	{
		connection.execute("select (id, login, password, name, surname, role) from user where id='" + std::to_string(id) + "'");
		auto_ptr<ResultSet> res = connection.getResultSet();

		return new User(res.get());
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	return nullptr;
}

User DAOUser::getByLogin(MySQLAccess connection, string login) const
{
	try
	{
		connection.execute("select (id, login, password, name, surname, role) from user where login='" + login + "'");
		auto_ptr<ResultSet> res = connection.getResultSet();

		return User(res.get());
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getByLogin() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByLogin() occured.\n";
		cerr << exp.what() << endl;
	}

	return User();
}

vector<User> DAOUser::getByName(MySQLAccess connection, string name) const
{
	vector<User> result;

	try
	{
		connection.execute("select (id, name, surname, role) from user where name='" + name + "' ORDER BY id");
		auto_ptr<ResultSet> res = connection.getResultSet();

		while (res->next())
		{
			User user(res.get());
			result.push_back(user);
		}
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	return result;
}

vector<User> DAOUser::getBySurname(MySQLAccess connection, string surname) const
{
	vector<User> result;

	try
	{
		connection.execute("select (id, name, surname, role) from user where surname='" + surname + "' ORDER BY id");
		auto_ptr<ResultSet> res = connection.getResultSet();

		while (res->next())
		{
			User user(res.get());
			result.push_back(user);
		}
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getBySurname() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getBySurname() occured.\n";
		cerr << exp.what() << endl;
	}

	return result;
}

vector<User> DAOUser::getByFullName(MySQLAccess connection, string name, string surname) const
{
	vector<User> result;

	try
	{
		connection.execute("select (id, name, surname, role) from user where name='" + name + "' AND surname='" + surname + "'");
		auto_ptr<ResultSet> res = connection.getResultSet();

		while (res->next())
		{
			User user(res.get());
			result.push_back(user);
		}
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getByFullName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByFullName() occured.\n";
		cerr << exp.what() << endl;
	}

	return result;
}

vector<User> DAOUser::getByGroup(MySQLAccess connection, string group) const
{
	vector<User> result;

	try
	{
		connection.execute("select (id, name, surname, role) from user where group='" + group + "' ORDER BY surname");
		auto_ptr<ResultSet> res = connection.getResultSet();

		while (res->next())
		{
			User user(res.get());
			result.push_back(user);
		}
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getByGroup() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByGroup() occured.\n";
		cerr << exp.what() << endl;
	}

	return result;
}

//Setters

void DAOUser::add(MySQLAccess connection, const User& user) const
{
	try
	{
		connection.execute("INSERT INTO user (name, surname, role) VALUES ('" + user.getName() + "', '" + user.getSurname() + "', " + std::to_string(user.getRoleID()) + ")");
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::add() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::add() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOUser::updateLogin(MySQLAccess connection, const User& user, string newLogin) const
{
	try
	{
		connection.execute("UPDATE user SET login='" + newLogin + "' WHERE id=" + std::to_string(user.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::updateLogin() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::updateLogin() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOUser::updateName(MySQLAccess connection, const User& user, string newName) const
{
	try
	{
		connection.execute("UPDATE user SET name='" + newName + "' WHERE id=" + std::to_string(user.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::updateName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::updateName() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOUser::updateSurname(MySQLAccess connection, const User& user, string newSurname) const
{
	try
	{
		connection.execute("UPDATE user SET surname='" + newSurname + "' WHERE id=" + std::to_string(user.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::updateSurname() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::updateSurname() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOUser::updateRole(MySQLAccess connection, const User& user, int newRole) const
{
	try
	{
		connection.execute("UPDATE user SET role=" + std::to_string(newRole) + " WHERE id=" + std::to_string(user.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::updateRole() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::updateRole() occured.\n";
		cerr << exp.what() << endl;
	}
}
