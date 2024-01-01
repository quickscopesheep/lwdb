#include "server.h"

Server* createServer(u_short port, void (*callback)(Server* server), int* result){
    Server* server = (Server*)malloc(sizeof(Server));
    server->connect_callback = callback;

    server->listen = socket(AF_INET, SOCK_STREAM, NULL);
    server->server.sin_family = AF_INET;
	server->server.sin_port = htons(port);
	InetPton(AF_INET, _T("127.0.0.1"), &server->server.sin_addr);

    *result = bind(server->listen, (struct sockaddr*)&server->server, sizeof(server->server));

    return server;
}

int listenServer(Server* server){
    int iResult;

    while(true){
        iResult = listen(server->listen, AF_INET);

        sockaddr clientAddr;
        int addressLength;

        SOCKET clientS = accept(server->listen, &clientAddr, &addressLength);
        if (clientS == SOCKET_ERROR) {
		    printf("error creating client socket", WSAGetLastError());
            return -1;
	    }

        recv(clientS, server->RecieveBuffer, BUFFER_LENGTH, NULL);

        (*server->connect_callback)(server);

        send(clientS, server->SendBuffer, BUFFER_LENGTH, NULL);

	    closesocket(clientS);
    }

    return 0;
}

int closeServer(Server* server){
    closesocket(server->listen);
    free(server);
    
    return 0;
}