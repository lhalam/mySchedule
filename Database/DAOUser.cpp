#include "DAOUser.h"
#include "DAORole.h"

DAOUser::DAOUser(MySQLAccess conn):
	DAO(conn)
{
}

Entity * DAOUser::getById(unsigned id) const
{
	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, login, password, name, surname, role) from users where id='" + std::to_string(id) + "'");
		Role *role = dynamic_cast<Role*>(DAORole(connection).getById(res->getInt("role")));
		User *user =  new User(unsigned(res->getInt("id")), role->getID(), role->getStatus(), res->getString("name"), res->getString("surname"), res->getString("password"));
		delete role;
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

	return nullptr;
}

vector<User> DAOUser::getByName(string name) const
{
	vector<User> result;

	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name, surname, role) from users where name='" + name + "' ORDER BY id");

		while (res->next())
		{
			result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
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

vector<User> DAOUser::getBySurname(string surname) const
{
	vector<User> result;

	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name, surname, role) from users where surname='" + surname + "' ORDER BY id");
		while (res->next())
		{
			result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
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

vector<User> DAOUser::getByFullName(string name, string surname) const
{
	vector<User> result;

	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name, surname, role) from users where name='" + name + "' AND surname='" + surname + "'");
		while (res->next())
		{
			result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
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

vector<User> DAOUser::getByGroup(string group) const
{
	vector<User> result;

	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name, surname, role) from users where group='" + group + "' ORDER BY surname");
		while (res->next())
		{
			result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
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

void DAOUser::addUser(const User& user) const
{
	try
	{
		connection.execute("INSERT INTO users (name, surname, role) VALUES ('" + user.getName() + "', '" + user.getSurname() + "', " + std::to_string(user.getRole()) + ")");
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::addUser() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::addUser() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAOUser::updateName(const User& user, string newName) const
{
	try
	{
		connection.execute("UPDATE users SET name='" + newName + "' WHERE id=" + std::to_string(user.getId()));
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

void DAOUser::updateSurname(const User& user, string newSurName) const
{
	try
	{
		connection.execute("UPDATE users SET surname='" + newSurName + "' WHERE id=" + std::to_string(user.getId()));
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

void DAOUser::updateRole(const User& user, int newRole) const
{
	/*
		check availability of the role newRole
	*/

	try
	{
		connection.execute("UPDATE users SET role=" + std::to_string(newRole) + " WHERE id=" + std::to_string(user.getId()));
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
