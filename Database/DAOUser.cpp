#include "DAOUser.h"

Entity DAOUser::getById(unsigned id) const
{
	try
	{
		auto_ptr<ResultSet> res = query("select (id, name, surname, role) from users where id='" + std::to_string(id) + "'");
		return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOUser::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOUser::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	return User();
}

vector<User> DAOUser::getByName(string name) const
{
	vector<User> result;

	try
	{
		auto_ptr<sql::Statement> stmt(connection->createStatement());
		stmt->execute("select (id, name, surname, role) from users where name='" + name + "' ORDER BY id");
		auto_ptr<ResultSet> res;
		
		do
		{
			res.reset(stmt->getResultSet());
			
			while (res->next())
			{
				result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
			}
		} while (stmt->getMoreResults());
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
		auto_ptr<sql::Statement> stmt(connection->createStatement());
		stmt->execute("select (id, name, surname, role) from users where surname='" + surname + "' ORDER BY id");
		auto_ptr<ResultSet> res;

		do
		{
			res.reset(stmt->getResultSet());

			while (res->next())
			{
				result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
			}
		} while (stmt->getMoreResults());
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
		auto_ptr<sql::Statement> stmt(connection->createStatement());
		stmt->execute("select (id, name, surname, role) from users where name='" + name + "' AND surname='" + surname + "'");
		auto_ptr<ResultSet> res;

		do
		{
			res.reset(stmt->getResultSet());

			while (res->next())
			{
				result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
			}
		} while (stmt->getMoreResults());
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
		auto_ptr<sql::Statement> stmt(connection->createStatement());
		stmt->execute("select (id, name, surname, role) from users where group='" + group + "' ORDER BY surname");
		auto_ptr<ResultSet> res;

		do
		{
			res.reset(stmt->getResultSet());

			while (res->next())
			{
				result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
			}
		} while (stmt->getMoreResults());
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
		query("INSERT INTO users (name, surname, role) VALUES ('" + user.getName() + "', '" + user.getSurname() + "', " + std::to_string(user.getRole()) + ")");
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
		query("UPDATE users SET name='" + newName + "' WHERE id=" + std::to_string(user.getId()));
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
		query("UPDATE users SET surname='" + newSurName + "' WHERE id=" + std::to_string(user.getId()));
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
		query("UPDATE users SET role=" + std::to_string(newRole) + " WHERE id=" + std::to_string(user.getId()));
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
