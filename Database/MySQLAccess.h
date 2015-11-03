#pragma once

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "mysql_connection.h"

#include <cppconn\driver.h>
#include <cppconn\exception.h>
#include <cppconn\resultset.h>
#include <cppconn\statement.h>
#include <cppconn\prepared_statement.h>

using namespace std;

using sql::Connection;
using sql::Statement;
using sql::ResultSet;
using sql::SQLString;
using sql::SQLException;

class MySQLAccess {
private:
	auto_ptr<Connection> con;
	auto_ptr<Statement> stmt;
	
public:
	MySQLAccess(const string url, const string user, const string pass, const string db);
	~MySQLAccess();

	void close();
	bool execute(const SQLString&);
	int executeUpdate(const SQLString&);
	ResultSet* executeQuery(const SQLString&);

private:
	void exceptionResult(SQLException&);

	MySQLAccess(const MySQLAccess&) = delete;
	MySQLAccess& operator=(const MySQLAccess&) = delete;
};
