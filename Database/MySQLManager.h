#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

/*
MySQLManager handles all the database connections in the project.
It is a singleton.
*/
class MySQLManager
{
private:
	vector<MySQLAccess> connections;
	unsigned int maxNumOfConnections;
	/*Data used to connect to the database*/
	string database;
	string user;
	string password;

	MySQLManager(string database, string user, string password, unsigned int maxNumOfConnections);
	MySQLManager(const MySQLManager&);

public:
	static MySQLManager& getInstance(string database, string user, string password, unsigned int maxNumOfConnections);

	MySQLAccess getConnection();
	
	/*
	To be added in the near future:
	1. Close one particular connection
	2. Close all connections
	*/

	unsigned int numberOfConnections() const;
};