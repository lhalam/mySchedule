#include "globals.h"

const DAOAssignment& daoAssignment = *DAOAssignment::getInstance();
const DAOEvent& daoEvent = *DAOEvent::getInstance();
const DAOGroup& daoGroup = *DAOGroup::getInstance();
const DAORole& daoRole = *DAORole::getInstance();
const DAOUser& daoUser = *DAOUser::getInstance();

Session* session = Session::getInstance();

DBLogger*	  DBLogger::dblogger_instance = nullptr;
ServerLogger* ServerLogger::slogger_instance = nullptr;
ConfigLogger* ConfigLogger::clogger_instance = nullptr;

LogLevel Logger::ReportingLevel = LogLevel::logError;

map<string, map<string, string>> config = Config("myschedule.config").getConfig();
