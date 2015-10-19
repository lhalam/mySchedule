#include <exception>
#include "MySQLManager.h"

using std::overflow_error;

MySQLManager::MySQLManager(string database, string user, string password, unsigned int maxNumOfConnections):
	maxNumOfConnections(maxNumOfConnections),
	database(database),
	user(user),
	password(password)
{
}

MySQLManager& MySQLManager::getInstance(string database, string user, string password, unsigned int maxNumOfConnections)
{
	static MySQLManager manager(database, user, password, maxNumOfConnections);
	return manager;
}

MySQLAccess MySQLManager::getConnection()
{
	if (numberOfConnections() < maxNumOfConnections)
	{
		MySQLAccess newConnection(database, user, password);
		connections.push_back(newConnection);

		return newConnection;
	}
	else
	{
		throw overflow_error("Failed to connect to the database. Too many connections.");
	}
}

unsigned int MySQLManager::numberOfConnections() const
{
	return connections.size();
}