#pragma once

#include "DAOGroup.h"
#include "DAOUser.h"

class Assignment : public Entity
{
private:
	str subjectName;
	str task;
	Group group;
	User lecturer;

public:
	Assignment() :
		Entity(),
		subjectName(),
		task(),
		group(),
		lecturer()
	{
	}

	Assignment(
		uni id,
		str subN,
		str t,
		Group gr,
		User teacher
		) :

		Entity(id),
		subjectName(subN),
		task(t),
		group(gr),
		lecturer(teacher)
	{
	}

	Assignment(MySQLAccess *connection, const ResultSet *res) :
		Entity(res),
		subjectName(res->getString("name").asStdString()),
		task(res->getString("task").asStdString())
	{
		Group *g = dynamic_cast<Group*>(DAOGroup::getInstance()->getById(connection, res->getInt("group_id")));
		this->group = *g;
		delete g;

		User *lect = dynamic_cast<User*>(DAOUser::getInstance()->getById(connection, res->getInt("user_id")));
		this->lecturer = *lect;
		delete lect;
	}

	void setID(uni ID) { this->id = ID; }
	uni getID() const { return this->id; }

	void setSubject(str subjN) { this->subjectName = subjN; }
	str getSubject() const { return this->subjectName; }

	void setTask(str t) { this->task = t; }
	str getTask() const { return this->task; }

	void setGroup(const Group& gr) { this->group = gr; }
	Group getGroup() const { return this->group; }

	void setLecturer(const User& user) { this->lecturer = user; }
	User getLecturer() const { return this->lecturer; }
};
