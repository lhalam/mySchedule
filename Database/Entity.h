#pragma once

#include <string>

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
	
	virtual void setID(uni) = 0;

	virtual uni getID() const = 0;


};