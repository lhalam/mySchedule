#include <exception>
#include <algorithm>
#include "MySQLManager.h"

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

MySQLManager& MySQLManager::getInstance(string url, string database, string user, string password, unsigned int maxNumOfConnections)
{
	static MySQLManager manager(url, database, user, password, maxNumOfConnections);
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