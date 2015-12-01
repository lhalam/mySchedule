#include "MySQLAccess.h"
#include "../globals.h"

void MySQLAccess::exceptionResult(sql::SQLException& e) {
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

	DBLogger::Instance()->Log(LogMessage(__FILE__, __LINE__, __FUNCTION__, string(e.what()), to_string(e.getErrorCode()), string(e.getSQLState())));
}

MySQLAccess::MySQLAccess(const string url, const string user, const string pass, const string db) {
	try {
		sql::Driver* driver(get_driver_instance());
		con = unique_ptr<sql::Connection>(driver->connect(url, user, pass));
		con->setSchema(db);
		stmt = unique_ptr<sql::Statement>(con->createStatement());
	}
	catch (sql::SQLException& e) {
		exceptionResult(e);
	}
	catch (...) { cout << "WTF"; }
}

MySQLAccess::~MySQLAccess() {
	if (!con->isClosed()) {
		con->close();
	}
}

void MySQLAccess::close() {
	if (!con->isClosed()) {
		con->close();
	}
}

bool MySQLAccess::execute(const sql::SQLString& sql) {
	try {
		return stmt->execute(sql);
	}
	catch (sql::SQLException& e) {
		exceptionResult(e);
	}
	return false;
}

int MySQLAccess::executeUpdate(const sql::SQLString& sql) {
	try {
		return stmt->executeUpdate(sql);
	}
	catch (sql::SQLException& e) {
		exceptionResult(e);
	}
	return -1;
}

sql::ResultSet* MySQLAccess::executeQuery(const sql::SQLString& sql) {
	try {
		return stmt->executeQuery(sql);
	}
	catch (sql::SQLException& e) {
		exceptionResult(e);
	}
	return nullptr;
}
