#pragma once

#include <string>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/un.h>

using namespace std;

class Server
{
    public:
        Server(string, int);
// Public variable
        string adr_server;
        int port_server;
// Public function
        void bind_server();
        void listen_server(string, int);
        void accept_connection();
    private:
        bool isOn;
        int server_fd;
        int client_fd;
        struct sockaddr my_addr;
        struct sockaddr peer_addr;
};
