/*
	Database access object (DAO) - an object,
	used to get or update entities in a database.
*/

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

#include "Entity.h"

using std::string;
using std::vector;
using std::auto_ptr;
using std::exception;
using std::cerr;
using std::endl;

using sql::ResultSet;
using sql::SQLException;

class DAO
{
protected:
	//Obsolete fields - will be deleted after creation of BaseConnection class
	string HOST;
	string USER;
	string PASSWORD;
	string DB;
	sql::Driver* driver;
	auto_ptr<sql::Connection> connection;

public:
	virtual Entity getById(unsigned id) = 0;
	
protected:
	DAO(string HOST, string USER, string PASSWORD, string DB);

	auto_ptr<ResultSet> query(string sql) const;
};
