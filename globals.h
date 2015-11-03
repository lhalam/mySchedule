#pragma once

#include "Database\DAOAssignment.h"
#include "Database\DAOEvent.h"
#include "Database\DAOGroup.h"
#include "Database\DAORole.h"
#include "Database\DAOUser.h"

#include "Logger\Logger.h"

const DAOAssignment& daoAssignment = *DAOAssignment::getInstance();
const DAOEvent& daoEvent = *DAOEvent::getInstance();
const DAOGroup& daoGroup = *DAOGroup::getInstance();
const DAORole& daoRole = *DAORole::getInstance();
const DAOUser& daoUser = *DAOUser::getInstance();

//Initializing a global static pointer
Logger* Logger::instanceUnique = NULL;

//Stating the default logging level
LogLevel Logger::ReportingLevel = LogLevel::logError;
