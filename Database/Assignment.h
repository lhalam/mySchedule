#pragma once

#include "Group.h"
#include "User.h"

class Assignment : public Entity
{
private:
	str subjectName;
	Group group;
	User lecturer;

public:
	Assignment() :
		Entity(),
		subjectName(),
		group(),
		lecturer()
	{
	}

	Assignment(
		uni id,
		str subN,
		Group gr,
		User teacher
		) :

		Entity(id),
		subjectName(subN),
		group(gr),
		lecturer(teacher)
	{
	}

	Assignment(const Assignment& h_a) :
		Entity(h_a.id),
		subjectName(h_a.subjectName),
		group(h_a.group),
		lecturer(h_a.lecturer)
	{
	}

	void setID(uni ID) { this->id = ID; }
	uni getID() const { return this->id; }

	void setSubject(str subjN) { this->subjectName = subjN; }
	str getSubject() const { return this->subjectName; }

	void setGroup(const Group& gr) { this->group = gr; }
	Group getGroup() const { return this->group; }

	void setLecturer(const User& user) { this->lecturer = user; }
	User getLecturer() const { return this->lecturer; }
};
