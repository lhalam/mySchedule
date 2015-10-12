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

	Role(const Role& role) :
		Entity(role.id),
		status(role.status)
	{
	}

	Role& operator = (const Role& r)
	{
		if (!(this->equals(r)))
		{
			this->id = r.id;
			this->status = r.status;
		}
		return (*this);
	}

	void setID(unsigned int id_) { this->id = id_; }
	unsigned int getID() const { return this->id; }

	void setStatus(str st) { this->status = st; }
	str getStatus() const { return this->status; }

	bool equals(const Role& r)
	{
		if (this->id == r.id && this->status == r.status)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};