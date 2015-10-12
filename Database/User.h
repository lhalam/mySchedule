#pragma once

#include "Role.h"

class User : public Entity
{
	
private:
	Role role;
	str firstName;
	str lastName;
	str password;

public:
	User(
		unsigned int personalID,
		unsigned int roleID,
		str roleStatus,
		str fName,
		str lName,
		str personalPassword
		) :

		Entity(personalID),
		role(roleID, roleStatus),
		firstName(fName),
		lastName(lName),
		password(personalPassword)
	{
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

};