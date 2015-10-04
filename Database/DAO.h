#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "User.h"

using std::string;
using std::vector;
using std::auto_ptr;

using sql::ResultSet;

class DAO
{
	string HOST;
	string USER;
	string PASSWORD;
	string DB;
	sql::Driver* driver;
	auto_ptr<sql::Connection> connection;

public:
	DAO(string HOST, string USER, string PASSWORD, string DB);
	User getUserById(unsigned int id) const;
	User getUserByName(string name) const;
	User getUserBySurname(string surname) const;
	User getUserByFullName(string name, string surname) const;
	vector<User> getUsersByGroup(string group) const;

private:
	auto_ptr<ResultSet> getResult(string sql) const;
};
