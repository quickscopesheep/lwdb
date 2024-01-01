#include "prerequisites.h"
#include "globals.h"

#include "server.h"

Globals globals;

//int createSocket(){
//    globals.listenerSocket = socket(AF_INET, SOCK_STREAM, NULL);
//    globals.server.sin_family = AF_INET;
//	globals.server.sin_port = htons(80);
//	InetPton(AF_INET, _T("127.0.0.1"), &globals.server.sin_addr);
//
//    return bind(globals.listenerSocket, (struct sockaddr*)&globals.server, sizeof(globals.server));
//}

int main(int argsc, char** argsv){
    int iResult;

    WSADATA wsa;
    if(WSAStartup(MAKEWORD(2, 2), &wsa)){
        printf("error starting WinSock");
        return -1;
    }

    Server* server = createServer(80, nullptr, &iResult);
    listenServer(server);
    closeServer(server);

    return 0;
}