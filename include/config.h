#pragma once
#include "prerequisites.h"

struct Config{
    short apiPort;

    int numColumns;
    int columnSize;

    char* authKey;
};

void loadConfig(const char* path, Config* cnfg);