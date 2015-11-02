#pragma once

#include "DAORole.h"
#include "DAOGroup.h"

class User : public Entity
{
	
private:
	Role role;
	Group group;
	str name;
	str surname;
	str login;
	str password;
	
public:
	User() :
		Entity(),
		role(),
		group(),
		name(),
		surname(),
		login(),
		password()
	{
	}

	User(
		unsigned int ID,
		Role r,
		Group g,
		str fName,
		str lName,
		str personalLogin,
		str personalPassword
		) :

		Entity(ID),
		role(r),
		group(g),
		name(fName),
		surname(lName),
		login(personalLogin),
		password(personalPassword)
	{
	}

	User(MySQLAccess *connection, const ResultSet *res) :
		Entity(res),
		name(res->getString("name").asStdString()),
		surname(res->getString("surname").asStdString()),
		login(res->getString("login").asStdString()),
		password(res->getString("password").asStdString())
	{
		Role *r = dynamic_cast<Role*>(DAORole::getInstance()->getById(connection, res->getInt("role_id")));
		this->role = *r;
		delete r;

		Group *g = dynamic_cast<Group*>(DAOGroup::getInstance()->getById(connection, res->getInt("group_id")));
		this->group = *g;
		delete g;
	}

	void setID(unsigned int id_) { this->id = id_; }
	unsigned int getID() const { return this->id; }

	void setLogin(str l) { this->login = l; }
	str getLogin() const { return this->login; }

	void setPassword(str pass) { this->password = pass; }
	str getPassword() const { return this->password; }

	void setName(str fName) { this->name = fName; }
	str getName() const { return this->name; }

	void setSurname(str lName) { this->surname = lName; }
	str getSurname() const { return this->surname; }

	void setRoleID(unsigned int id) { this->role.setID(id); }
	unsigned int getRoleID() const { return this->role.getID(); }

	void setStatus(str status) { this->role.setName(status); }
	str getStatus() const { return this->role.getName(); }

	void setGroupName(str gName) { this->group.setName(gName); }
	str getGroupName() const { return group.getName(); }

	void setGroupID(unsigned id) { this->group.setID(id); }
	int getGroupID() const { return group.getID(); }
};
