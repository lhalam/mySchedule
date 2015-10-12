#pragma once

#include "Entity.h"

typedef std::string str;

class Role : public Entity
{
private:
	str name;

public:
	Role() :
		Entity(),
		name(str())
	{
	}

	Role(
		unsigned int id, 
		str st
		) :

		Entity(id),
		name(st)
	{
	}

	Role(const Role& role) :
		Entity(role.id),
		name(role.name)
	{
	}


	void setID(unsigned int id_) { this->id = id_; }
	unsigned int getID() const { return this->id; }

	void setName(str st) { this->name = st; }
	str getName() const { return this->name; }

};