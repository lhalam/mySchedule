#include "globals.h"

const DAOAssignment& daoAssignment = *DAOAssignment::getInstance();
const DAOEvent& daoEvent = *DAOEvent::getInstance();
const DAOGroup& daoGroup = *DAOGroup::getInstance();
const DAORole& daoRole = *DAORole::getInstance();
const DAOUser& daoUser = *DAOUser::getInstance();

Logger* Logger::instanceUnique = NULL;

LogLevel Logger::ReportingLevel = LogLevel::logError;

map<string, map<string, string>> config = Config("myschedule.config").getConfig();
