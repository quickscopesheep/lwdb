#include "prerequisites.h"

#define BUFFER_LENGTH 1024

enum SERVER_FLAGS{
    
}

struct Server{
    SOCKET listen;
    sockaddr_in server;

    char SendBuffer[BUFFER_LENGTH];
    char RecieveBuffer[BUFFER_LENGTH];

    void (*connect_callback)(Server* server);

    unsigned int flags;
};

Server* createServer(u_short port, void (*callback)(Server* server), int* result);
int listenServer(Server* server);
int closeServer(Server* server);