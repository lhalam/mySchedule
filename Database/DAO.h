/*
	Database access object (DAO) - an object,
	used to get or update entities in a database.
*/

#pragma once
#pragma warning(disable: 4251)

#include <vector>
#include <stdexcept>

#include "Entity.h"
#include "MySQLAccess.h"

class DAO
{
public:
	//Returns a poiter which must be deleted afterwards
	virtual Entity * getById(MySQLAccess *connection, unsigned id) const = 0;
};
