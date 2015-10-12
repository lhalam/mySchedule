#include "DAOGroup.h"

DAOGroup::DAOGroup(MySQLAccess conn) :
	DAO(conn)
{
}

Entity DAOGroup::getById(unsigned id) const
{
	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name) from groups where id=" + std::to_string(id));
		return Group(res->getInt("id"), res->getString("name"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOGroup::getById() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOGroup::getById() occured.\n";
		cerr << exp.what() << endl;
	}
}

Group DAOGroup::getByName(string name) const
{
	try
	{
		auto_ptr<ResultSet> res = connection.execute("select (id, name) from groups where name=" + name);
		return Group(res->getInt("id"), res->getString("name"));
	} catch (SQLException& exp)
	{
		cerr << "An SQL exception in DAOGroup::getByName() occured.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAOGroup::getByName() occured.\n";
		cerr << exp.what() << endl;
	}
}
