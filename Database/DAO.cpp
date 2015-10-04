#include "DAO.h"

DAO::DAO(string HOST, string USER, string PASSWORD, string DB):
	driver(get_driver_instance()),
	connection(std::auto_ptr<sql::Connection>(driver->connect(HOST, USER, PASSWORD)))
{
	connection->setSchema(DB);
}
User DAO::getUserById(unsigned int id) const
{
	std::auto_ptr<sql::Statement> stmt(connection->createStatement());
	stmt->execute("select (id, name, surname, role) from users where id='" + std::to_string(id) + "'");
	std::auto_ptr< sql::ResultSet > res;
	res.reset(stmt->getResultSet());	
	
	return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
}
User DAO::getUserByName(string name) const
{
	std::auto_ptr<sql::Statement> stmt(connection->createStatement());
	stmt->execute("select (id, name, surname, role) from users where name='" + name + "'");
	std::auto_ptr< sql::ResultSet > res;
	res.reset(stmt->getResultSet());

	return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
}
User DAO::getUserBySurname(string surname) const
{
	std::auto_ptr<sql::Statement> stmt(connection->createStatement());
	stmt->execute("select (id, name, surname, role) from users where surname='" + surname + "'");
	std::auto_ptr< sql::ResultSet > res;
	res.reset(stmt->getResultSet());

	return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
}
User DAO::getUser(string name, string surname) const
{
	std::auto_ptr<sql::Statement> stmt(connection->createStatement());
	stmt->execute("select (id, name, surname, role) from users where name='" + name + "' AND surname='" + surname + "'");
	std::auto_ptr< sql::ResultSet > res;
	res.reset(stmt->getResultSet());

	return User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role"));
}
vector<User> DAO::getUsersByGroup(string group) const
{
	vector<User> result;
	std::auto_ptr<sql::Statement> stmt(connection->createStatement());
	stmt->execute("select (id, name, surname, role) from users where group='"+group+"' ORDER BY name");
	std::auto_ptr< sql::ResultSet > res;
	do {
		res.reset(stmt->getResultSet());
		while (res->next()) {
			result.push_back(User(res->getInt("id"), res->getString("name"), res->getString("surname"), res->getInt("role")));
		}
	} while (stmt->getMoreResults());
	return result;
}