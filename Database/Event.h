#pragma once

#include "Entity.h"

class Event : public Entity
{
private:
	str name;

public:
	Event() :
		Entity(),
		name()
	{
	}

	Event(
		uni id,
		str name_
		) :

		Entity(id),
		name(name_)
	{
	}

	Event(const ResultSet *res) :
		Entity(res),
		name(res->getString("name").asStdString())
	{
	}

	void setID(uni id_) { this->id = id_; }
	uni getID() const { return this->id; }

	void setName(str name_) { this->name = name_; }
	str getName() const { return this->name; }
};
