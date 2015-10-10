#include "DAO.h"

DAO::DAO(string HOST, string USER, string PASSWORD, string DB) :
	driver(get_driver_instance()),
	connection(auto_ptr<sql::Connection>(driver->connect(HOST, USER, PASSWORD)))
{
	try
	{
		connection->setSchema(DB);
	} catch (SQLException& exp)
	{
		cerr << "Connection to " + DB + " failed.\n";
		cerr << exp.what() << endl;
	} catch (exception& exp)
	{
		cerr << "An exception in DAO constructor occured.\n";
		cerr << exp.what() << endl;
	}
}

auto_ptr<ResultSet> DAO::query(string sql) const
{
	auto_ptr<sql::Statement> stmt(connection->createStatement());
	stmt->execute(sql);

	auto_ptr<ResultSet> res;
	res.reset(stmt->getResultSet());

	return res;
}
