#pragma once

#include "Role.h"

class User : public Entity
{
	
private:
	Role role;
	str name;
	str surname;
	str login;
	str password;
	
public:
	User() :
		Entity(),
		role(),
		name(),
		surname(),
		login(),
		password()
	{
	}

	User(
		unsigned int personalID,
		unsigned int roleID,
		str roleStatus,
		str fName,
		str lName,
		str personalLogin,
		str personalPassword
		) :

		Entity(personalID),
		role(roleID, roleStatus),
		name(fName),
		surname(lName),
		password(personalPassword),
		login(personalLogin)
	{
	}

	User(const User& user) :
		Entity(user.id),
		role(user.role),
		name(user.name),
		surname(user.surname),
		password(user.password),
		login(user.login)
	{
	}


	void setID(unsigned int id_) { this->id = id_; }
	unsigned int getID() const { return this->id; }

	void setRoleID(unsigned int id) { this->role.setID(id); }
	unsigned int getRoleID() const { return this->role.getID(); }

	void setName(str fName) { this->name = fName; }
	str getName() const { return this->name; }

	void setSurname(str lName) { this->surname = lName; }
	str getSurname() const { return this->surname; }

	void setStatus(str status) { this->role.setName(status); }
	str getStatus() const { return this->role.getName(); }

	void setPassword(str pass) { this->password = pass; }
	str getPassword() const { return this->password; }

	void setLogin(str l) { this->login = l; }
	str getLogin() const { return this->login; }

};