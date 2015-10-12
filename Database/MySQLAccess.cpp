#include "MySQLAccess.h"

MySQLAccess::MySQLAccess(const string url, const string user, const string pass) {
	try {
		sql::Driver* driver(get_driver_instance());
		con = auto_ptr<sql::Connection>(driver->connect(url, user, pass));
		stmt = auto_ptr<sql::Statement>(con->createStatement());
	}
	catch (sql::SQLException &e) {
		/*
		MySQL Connector/C++ throws three different exceptions:
		- sql::MethodNotImplementedException (derived from sql::SQLException)
		- sql::InvalidArgumentException (derived from sql::SQLException)
		- sql::SQLException (derived from std::runtime_error)
		*/
		cout << "# ERR: SQLException in " << __FILE__;
		cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
		/* what() (derived from std::runtime_error) fetches error message */
		cout << "# ERR: " << e.what();
		cout << " (MySQL error code: " << e.getErrorCode();
		cout << ", SQLState: " << e.getSQLState() << " )" << endl;
	}
}

MySQLAccess::~MySQLAccess() {
	con->close();
}

sql::Connection* MySQLAccess::getConnection() {
	return con.get();
}

bool MySQLAccess::execute(const sql::SQLString& sql) {
	return stmt->execute(sql);
}

auto_ptr<sql::ResultSet> MySQLAccess::getResultSet() {
	auto_ptr<sql::ResultSet> retVal;
	retVal.reset(stmt->getResultSet());
	return retVal;
}
