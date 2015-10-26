#pragma once

#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>

#include "mysql_connection.h"

#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

using namespace std;

class MySQLAccess {
public:
	MySQLAccess(const string, const string, const string, const string);
	//MySQLAccess(const MySQLAccess&);
	//MySQLAccess& operator=(const MySQLAccess&);
	~MySQLAccess();
	void close();
	bool execute(const sql::SQLString&);
	int executeUpdate(const sql::SQLString&);
	sql::ResultSet* executeQuery(const sql::SQLString&);
	
	/* possible realization:
	/* MySQLAccess - abstract class
	/* u can only operate with pointers on objects of this class
	/*
	//static MySQLAccess* getInstance(const string, const string, 
	//			const string, const string);
	 */  

private:
	void exceptionResult(sql::SQLException&);

	auto_ptr<sql::Connection> con;
	auto_ptr<sql::Statement> stmt;
};
