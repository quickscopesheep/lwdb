#pragma once

#define BUFFER_LENGTH 1024

struct Globals{
    SOCKET listenerSocket;
	sockaddr_in server;

    char SendBuffer[BUFFER_LENGTH] = "/HTTP/1.1 200 OK\nContent-Length: 12\n\nHello World\n";
    char RecieveBuffer[BUFFER_LENGTH];
};

extern Globals globals;