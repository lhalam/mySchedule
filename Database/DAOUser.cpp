#include "DAOUser.h"
#include "DAORole.h"

const DAOUser * DAOUser::getInstance()
{
	static DAOUser instance;
	return &instance;
}

//Getters

Entity * DAOUser::getById(MySQLAccess *connection, unsigned id) const
{
	ResultSet *res = nullptr;
	try
	{
		res = connection->executeQuery(
			"select * from `user` where id=" + to_string(id));
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
			"select * from `user` where login='" + login + "'");
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
			"select * from `user` where name='" + name + "' order by id");

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
			"select * from `user` where surname='" + surname +
			"' order by id");

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
			"select * from `user` where name='" + name +
			"' and surname='" + surname + "'");

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
			"select * from `user` where role_id=" + to_string(roleID) +
			"order by surname");

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
			"select * from `user` where group_id=" + to_string(groupID) +
			"order by surname");

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
		connection->execute("insert into `user` "
			"(login, password, name, surname, role_id, group_id) values ('" +
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
		connection->execute("delete from `user` where id=" +
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
		connection->execute("update `user` set login='" + newLogin + "' "
			"where id=" + to_string(user.getID()));
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
		connection->execute("update `user` set name='" + newName + "' "
			"where id=" + to_string(user.getID()));
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
		connection->execute("update `user` set surname='" + newSurname + "' "
			"where id=" + to_string(user.getID()));
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
		connection->execute("update `user` set role=" + to_string(newRole) + " "
			"where id=" + to_string(user.getID()));
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
		connection->execute("update `user` set role=" + to_string(newGroup) + " "
			"where id=" + to_string(user.getID()));
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
