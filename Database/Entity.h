#pragma once

#include <string>
#include <cppconn/resultset.h>

using sql::ResultSet;

typedef std::string str;
typedef unsigned int uni;

class Entity
{
private:

protected:
	uni id;

public:
	Entity() :
		id(0)
	{
	}

	Entity(uni id_) :
		id(id_)
	{
	}

	Entity(const ResultSet *res) :
		id(res->getInt("id"))
	{
	}
	
	virtual void setID(uni) = 0;

	virtual uni getID() const = 0;
};
