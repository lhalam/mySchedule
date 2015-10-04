#include "DAO.h"

using std::exception;
using std::cerr;
using std::endl;

using sql::SQLException;

DAO::DAO(string HOST, string USER, string PASSWORD, string DB):
	driver(get_driver_instance()),
	connection(auto_ptr<sql::Connection>(driver->connect(HOST, USER, PASSWORD)))
{
	try
	{
		connection->setSchema(DB);
	} catch (SQLException& exp)
	{
		cerr << "Connection to " + DB + " failed.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAO constructor occured.\n";
		cerr << exp.what() << endl;
	}
}

auto_ptr<ResultSet> DAO::query(string sql) const
{
	auto_ptr<sql::Statement> stmt(connection->createStatement());
	stmt->execute(sql);

	auto_ptr<ResultSet> res;
	res.reset(stmt->getResultSet());

	return res;
}

/* USER */

//Getters
User DAO::getUserById(unsigned int id) const
{
	try
	{
		auto_ptr<ResultSet> res = query("select (id, name, surname, role) from users where id='" + std::to_string(id) + "'");
		return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in getUserById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in getUserById() occured.\n";
		cerr << exp.what() << endl;
	}

	return User();
}

User DAO::getUserByName(string name) const
{
	try
	{
		auto_ptr<ResultSet> res = query("select (id, name, surname, role) from users where name='" + name + "'");
		return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in getUserByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in getUserByName() occured.\n";
		cerr << exp.what() << endl;
	}

	return User();
}

User DAO::getUserBySurname(string surname) const
{
	try
	{
		auto_ptr<ResultSet> res = query("select (id, name, surname, role) from users where surname='" + surname + "'");
		return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in getUserBySurname() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in getUserBySurname() occured.\n";
		cerr << exp.what() << endl;
	}

	return User();
}

User DAO::getUserByFullName(string name, string surname) const
{
	try
	{
		auto_ptr<ResultSet> res = query("select (id, name, surname, role) from users where name='" + name + "' AND surname='" + surname + "'");
		return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in getUserByFullName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in getUserByFullName() occured.\n";
		cerr << exp.what() << endl;
	}

	return User();
}

vector<User> DAO::getUsersByGroup(string group) const
{
	vector<User> result;
	try
	{
		auto_ptr<sql::Statement> stmt(connection->createStatement());
		stmt->execute("select (id, name, surname, role) from users where group='" + group + "' ORDER BY name");
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
		cerr << "An SQL exception in getUsersByGroup() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in getUsersByGroup() occured.\n";
		cerr << exp.what() << endl;
	}

	return result;
}

//Setters
void DAO::addUser(const User& user) const
{
	try
	{
		query("INSERT INTO users (name, surname, role) VALUES ('" + user.getName() + "', '" + user.getSurname() + "', " + std::to_string(user.getRole()) + ")");
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAO::updateUserName(const User& user, string newName) const
{
	try
	{
		query("UPDATE users SET name='" + newName + "' WHERE id=" + std::to_string(user.getId()));
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAO::updateUserSurname(const User& user, string newSurName) const
{
	try
	{
		query("UPDATE users SET surname='" + newSurName + "' WHERE id=" + std::to_string(user.getId()));
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
}

void DAO::updateUserRole(const User& user, int newRole) const
{
	/*
	checking availability of the role newRole
	*/
	try
	{
		query("UPDATE users SET role=" + std::to_string(newRole) + " WHERE id=" + std::to_string(user.getID()));
	}
	catch (SQLException& exp)
	{
		cerr << "An SQL exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
	catch (exception& exp)
	{
		cerr << "An exception in addUser() occured.\n";
		cerr << exp.what() << endl;
	}
}
