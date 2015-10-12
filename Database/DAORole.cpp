#include "DAORole.h"

Entity * DAORole::getById(unsigned id) const
{
	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name) from roles where id='" + std::to_string(id) + "'");
		return new Role(unsigned(res->getInt("id")), res->getString("name"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAORole::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAORole::getById() occured.\n";
		cerr << exp.what() << endl;
	}

	return nullptr;
}

Role DAORole::getByName(string name) const
{
	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name) from roles where name='" + name + "'");
		return Role(unsigned(res->getInt("id")), res->getString("name"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAORole::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAORole::getByName() occured.\n";
		cerr << exp.what() << endl;
	}

	return Role(0, "0");
}
