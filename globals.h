#pragma once

#include "Database\DAOAssignment.h"
#include "Database\DAOEvent.h"
#include "Database\DAOGroup.h"
#include "Database\DAORole.h"
#include "Database\DAOUser.h"

#include "Logger\Logger.h"
#include "Config\Config.h"

extern const DAOAssignment& daoAssignment;
extern const DAOEvent& daoEvent;
extern const DAOGroup& daoGroup;
extern const DAORole& daoRole;
extern const DAOUser& daoUser;

extern map<string, map<string, string>> config;
