#include <exception>
#include <algorithm>
#include "MySQLManager.h"

#include "..\globals.h"

using std::overflow_error;
using std::logic_error;
using std::find;

MySQLManager::MySQLManager(string url, string database, string user, string password, unsigned int maxNumOfConnections):
	url(url),
	maxNumOfConnections(maxNumOfConnections),
	database(database),
	user(user),
	password(password)
{
}

MySQLManager::~MySQLManager()
{
	for (MySQLAccess* connection : connections)
	{
		delete connection;
	}
}

MySQLManager& MySQLManager::getInstance()
{
	static MySQLManager manager(config["db"]["host"], config["db"]["db_name"],
		config["db"]["user"], config["db"]["pass"], stoi(config["db"]["pool_size"]));
	return manager;
}

MySQLAccess* MySQLManager::getConnection()
{
	if (numberOfConnections() < maxNumOfConnections)
	{
		MySQLAccess* newConnection = new MySQLAccess(url, user, password, database);
		connections.push_back(newConnection);

		return newConnection;
	}
	else
	{
		throw overflow_error("Failed to connect to the database. Too many connections.");
	}
}

void MySQLManager::closeConnection(MySQLAccess* connection)
{
	try
	{
		connections.erase(find(connections.begin(), connections.end(), connection));
	}
	catch (...)
	{
		throw logic_error("Could not safely close connection");
	}
	delete connection;
}

unsigned int MySQLManager::numberOfConnections() const
{
	return connections.size();
}