#pragma once

#include "Group.h"
#include "User.h"

class Home_Assignment : public Entity
{
private:
	str subjectName;
	Group group;
	User mentor;

public:
	Home_Assignment(
		uni id,
		str subN,
		Group gr,
		User teacher
		) :

		Entity(id),
		subjectName(subN),
		group(gr),
		mentor(teacher)
	{
	}

	Home_Assignment(const Home_Assignment& h_a) :
		Entity(h_a.id),
		subjectName(h_a.subjectName),
		group(h_a.group),
		mentor(h_a.mentor)
	{
	}

	void setID(uni ID) { this->id = ID; }
	uni getID() const { return this->id; }

	void setSubject(str subjN) { this->subjectName = subjN; }
	str getSubject() const { return this->subjectName; }

	void setGroup(Group& gr) { this->group = gr; }
	Group getGroup() const { return this->group; }

	void setMentor(User& user) { this->mentor = user; }
	User getMentor() const { return this->mentor; }
};
