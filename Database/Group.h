#pragma once

#include "Entity.h"

class Group : public Entity
{
private:
	str name;

public:
	Group(
		uni id, 
		str name_
		) :

		Entity(id),
		name(name_)
	{
	}

	Group(const Group& group) :
		Entity(group.id),
		name(group.name)
	{
	}

	Group& operator = (const Group& gr)
	{
		if (!(this->equals(gr)))
		{
			this->id = gr.id;
			this->name = gr.name;
		}
		return (*this);
	}

	void setID(uni id_) { this->id = id_; }
	uni getID() const { return this->id; }

	void setName(str name_) { this->name = name_; }
	str getName() const { return this->name; }

	bool equals(const Group& gr)
	{
		if (this->id == gr.id && this->name == gr.name)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};