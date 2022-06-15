#include <iostream>
#include <sys/socket.h>
#include "../../include/server.hpp"

int main(void)
{
    Server server("127.0.0.1", 4444);
    server.bind_server();
    server.listen_server(server.adr_server, server.port_server);
    server.accept_connection();
    return 0;
}
