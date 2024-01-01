#include "prerequisites.h"

#include "globals.h"

#include "database.h"
#include "server.h"

Globals globals = Globals();

void connect_callback(Server* server){
    printf(server->RecieveBuffer);

    memset(server->SendBuffer, 0, BUFFER_LENGTH);
    sprintf(server->SendBuffer, "/HTTP/1.1 200 OK\nContent-Length: 12\n\nHello World\n");
}

int main(int argsc, char** argsv){
    int iResult;

    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2, 2), &wsa)){
        printf("error starting WinSock\n");
        return -1;
    }

    globals.webAPI = createServer(80, 0, &connect_callback, &iResult);
    listenServer(globals.webAPI);
    closeServer(globals.webAPI);


    return 0;
}