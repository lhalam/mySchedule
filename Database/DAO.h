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
#include "MySQLAccess.h"

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
public:
	//Returns a poiter which must be deleted afterwards
	virtual Entity * getById(MySQLAccess& connection, unsigned id) const = 0;
};
