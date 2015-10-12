#pragma once

#include "Entity.h"

typedef std::string str;

class Role : public Entity
{
private:
	str status;

public:
	Role(
		unsigned int id, 
		str st
		) :

		Entity(id),
		status(st)
	{
	}

	void setID(unsigned int id_) { this->id = id_; }
	unsigned int getID() const { return this->id; }

	void setStatus(str st) { this->status = st; }
	str getStatus() const { return this->status; }
};