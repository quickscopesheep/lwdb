#pragma once

#include "prerequisites.h"

#define BUFFER_LENGTH 1024

enum ServerFlags{
    DEBUG_VERBOSE = 1
};

struct Server{
    SOCKET listen;
    sockaddr_in server;

    char SendBuffer[BUFFER_LENGTH];
    char RecieveBuffer[BUFFER_LENGTH];

    void (*connect_callback)(Server* server);

    unsigned int flags;
};

Server* createServer(u_short port, unsigned int flags, void (*callback)(Server* server), int* result);

int isServerFlag(Server* server, unsigned int flag);

int listenServer(Server* server);
int closeServer(Server* server);