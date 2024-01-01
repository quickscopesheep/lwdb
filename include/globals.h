#pragma once
#include "prerequisites.h"

#include "config.h"
#include "server.h"
#include "database.h"

struct Globals{
    Database* db;
    Server* webAPI;

    Config* config;
};

extern Globals globals;