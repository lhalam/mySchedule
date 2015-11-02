#pragma once

#include "Entity.h"

class Group : public Entity
{
private:
	str name;

public:
	Group() :
		Entity(),
		name()
	{
	}

	Group(
		uni id, 
		str name_
		) :

		Entity(id),
		name(name_)
	{
	}

	Group(const ResultSet *res) :
		Entity(res),
		name(res->getString("name").asStdString())
	{
	}

	void setID(uni id_) { this->id = id_; }
	uni getID() const { return this->id; }

	void setName(str name_) { this->name = name_; }
	str getName() const { return this->name; }
};
