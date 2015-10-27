#pragma once
#include <vector>
#include <string>

#include "MySQLAccess.h"

using std::vector;
using std::string;

/*
MySQLManager handles all the database connections in the project.
It is a singleton.
*/
class MySQLManager
{
private:
	vector<MySQLAccess*> connections;
	unsigned int maxNumOfConnections;
	/*Data used to connect to the database*/
	string url;
	string database;
	string user;
	string password;

public:
	static MySQLManager& getInstance(string url, string database, string user, string password, unsigned int maxNumOfConnections);

	~MySQLManager();

	MySQLAccess* getConnection();
	void closeConnection(MySQLAccess* connection);

	unsigned int numberOfConnections() const;

private:
	MySQLManager(string url, string database, string user, string password, unsigned int maxNumOfConnections);

	MySQLManager(const MySQLManager&) = delete;
	MySQLManager& operator=(const MySQLManager&) = delete;
};