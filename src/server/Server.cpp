#include "../../include/server.hpp"
#include <stdio.h>

using namespace std;

Server::Server(string adr, int port)
{
    adr_server = adr;
    port_server = port;
    isOn = false;
    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (server_fd == -1) {
        cerr << "\033[0;31m[*] Socket Error !\033[0;37m\n";
        exit (1);
    }
    memset(&my_addr, 0, sizeof(sockaddr));
    my_addr.sa_family = AF_UNIX;
}

void Server::bind_server()
{
    int bind_value = 0;

    // BIND THE SERVER
    bind_value = bind(server_fd, (struct sockaddr *) &my_addr, sizeof(my_addr));
    if (bind_value == -1) {
        perror("Bind");
        cerr << "\033[0;31m[*] Bind Error !\033[0;37m\n";
        exit(1);
    }
    cout << "[*] Creating Server...\n";
}

void Server::listen_server(string adr_server, int port_server)
{
    // LISTENING FOR CLIENTS
    int listening = 0;

    listening = listen(server_fd, 2);
    if (listening == -1) {
        perror("Listening");
        cerr << "\033[0,31m[*] Listening Error !\033[0;37m\n";
        exit(1);
    }
    cout << "[*] Server is listening on " << adr_server << ":" << port_server << endl;
}

void Server::accept_connection()
{
    // ACCEPT CONNECTION FROM THE CLIENT
    socklen_t len_peer_addr = sizeof(peer_addr);

    client_fd = accept(server_fd, (struct sockaddr *) &peer_addr, &len_peer_addr);
    if (client_fd == -1) {
        perror("ACCEPT");
        cerr << "\033[0,31m[*] Connection Error !\033[0;37m\n";
        exit(1);
    }
    cout << "[*] Waiting for clients connections....\n";
}
