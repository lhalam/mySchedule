/*
	Database access object (DAO) - an object,
	used to get or update entities in a database.
*/

#pragma once
#pragma warning(disable: 4251)

#include <string>
#include <vector>
#include <stdexcept>

#include "mysql_connection.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#include "Entity.h"
#include "MySQLAccess.h"

using std::string;
using std::vector;
using std::exception;
using std::cerr;
using std::endl;
using std::to_string;

using sql::ResultSet;
using sql::SQLException;

class DAO
{
public:
	//Returns a poiter which must be deleted afterwards
	virtual Entity * getById(MySQLAccess *connection, unsigned id) const = 0;
};
