#pragma once

#include "Role.h"

class User : public Entity
{
	
private:
	Role role;
	str firstName;
	str lastName;
	str login;
	str password;
	
public:
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
		firstName(fName),
		lastName(lName),
		password(personalPassword),
		login(personalLogin)
	{
	}

	User(const User& user) :
		Entity(user.id),
		role(user.role),
		firstName(user.firstName),
		lastName(user.lastName),
		password(user.password),
		login(user.login)
	{
	}

	User& operator = (const User& user)
	{
		if (!(this->equals(user)))
		{
			this->id = user.id;
			this->role = user.role;
			this->firstName = user.firstName;
			this->lastName = user.lastName;
			this->password = user.password;
			this->login = user.login;
		}
		return (*this);
	}

	void setID(unsigned int id_) { this->id = id_; }
	unsigned int getID() const { return this->id; }

	void setRoleID(unsigned int id) { this->role.setID(id); }
	unsigned int getRoleID() const { return this->role.getID(); }

	void setFirstName(str fName) { this->firstName = fName; }
	str getFirstName() const { return this->firstName; }

	void setLastName(str lName) { this->lastName = lName; }
	str getLastName() const { return this->lastName; }

	void setStatus(str status) { this->role.setStatus(status); }
	str getStatus() const { return this->role.getStatus(); }

	void setPassword(str pass) { this->password = pass; }
	str getPassword() const { return this->password; }

	void setLogin(str l) { this->login = l; }
	str getLogin() const { return this->login; }

	bool equals(const User& user)
	{
		if (this->id != user.id)
			return false;

		if (!(this->role.equals(user.role)))
			return false;

		if (this->firstName != user.firstName || this->lastName != user.lastName)
			return false;

		if (this->login != user.login)
			return false;

		return true;
	}
};