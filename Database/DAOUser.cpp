#include "DAOUser.h"
#include "DAORole.h"

const DAOUser * DAOUser::getInstance()
{
	static DAOUser instance;
	return &instance;
}

//Getters

User * DAOUser::getById(MySQLAccess *connection, unsigned id) const
{
	ResultSet *res = nullptr;
	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `user` WHERE id=" + to_string(id));
		res->next();

		User *user = new User(connection, res);
		delete res;
		return user;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return nullptr;
}

User DAOUser::getByLogin(MySQLAccess *connection, string login) const
{
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `user` WHERE login='" + login + "'");
		res->next();

		User user(connection, res);
		delete res;
		return user;
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getByLogin() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByLogin() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return User();
}

vector<User> DAOUser::getByName(MySQLAccess *connection, string name) const
{
	vector<User> result;
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `user` WHERE name='" + name + "' ORDER BY id");

		while (res->next())
		{
			User user(connection, res);
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

	delete res;
	return result;
}

vector<User> DAOUser::getBySurname(MySQLAccess *connection, string surname) const
{
	vector<User> result;
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `user` WHERE surname='" + surname + "' "
			"ORDER BY id");

		while (res->next())
		{
			User user(connection, res);
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

	delete res;
	return result;
}

vector<User> DAOUser::getByFullName(MySQLAccess *connection, string name, string surname) const
{
	vector<User> result;
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `user` WHERE name='" + name + "' "
			"AND surname='" + surname + "'");

		while (res->next())
		{
			User user(connection, res);
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

	delete res;
	return result;
}

vector<User> DAOUser::getByRole(MySQLAccess *connection, int roleID) const
{
	vector<User> result;
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `user` WHERE role_id=" + to_string(roleID) + " "
			"ORDER BY surname");

		while (res->next())
		{
			User user(connection, res);
			result.push_back(user);
		}
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getByRole() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getByRole() occured.\n";
		cerr << exp.what() << endl;
	}

	delete res;
	return result;
}

vector<User> DAOUser::getByGroup(MySQLAccess *connection, int groupID) const
{
	vector<User> result;
	ResultSet *res = nullptr;

	try
	{
		res = connection->executeQuery(
			"SELECT * FROM `user` WHERE group_id=" + to_string(groupID) + " "
			"ORDER BY surname");

		while (res->next())
		{
			User user(connection, res);
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

	delete res;
	return result;
}

//Setters

void DAOUser::add(MySQLAccess *connection, const User& user) const
{
	try
	{
		connection->execute("INSERT INTO `user` "
			"(login, password, name, surname, role_id, group_id) VALUES ('" +
			user.getLogin() + "', '" + user.getPassword() + "', '" +
			user.getName()  + "', '" + user.getSurname() + "', " +
			to_string(user.getRoleID()) + ", " +
			to_string(user.getGroupID()) + ")");
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

void DAOUser::remove(MySQLAccess *connection, const User& user) const
{
	try
	{
		connection->execute("DELETE FROM `user` WHERE id=" +
			to_string(user.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::remove() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::remove() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOUser::updateLogin(MySQLAccess *connection, const User& user, string newLogin) const
{
	try
	{
		connection->execute("UPDATE `user` SET login='" + newLogin + "' "
			"WHERE id=" + to_string(user.getID()));
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

void DAOUser::updateName(MySQLAccess *connection, const User& user, string newName) const
{
	try
	{
		connection->execute("UPDATE `user` SET name='" + newName + "' "
			"WHERE id=" + to_string(user.getID()));
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

void DAOUser::updateSurname(MySQLAccess *connection, const User& user, string newSurname) const
{
	try
	{
		connection->execute("UPDATE `user` SET surname='" + newSurname + "' "
			"WHERE id=" + to_string(user.getID()));
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

void DAOUser::updateRole(MySQLAccess *connection, const User& user, int newRole) const
{
	try
	{
		connection->execute("UPDATE `user` SET role_id=" + to_string(newRole) + " "
			"WHERE id=" + to_string(user.getID()));
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

void DAOUser::updateGroup(MySQLAccess *connection, const User& user, int newGroup) const
{
	try
	{
		connection->execute("UPDATE `user` SET group_id=" + to_string(newGroup) + " "
			"WHERE id=" + to_string(user.getID()));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::updateGroup() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::updateGroup() occured.\n";
		cerr << exp.what() << endl;
	}
}
