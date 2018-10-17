#include "server.h"

void	listen_client(t_sock *sock)
{
    if (listen(sock->server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((sock->new_socket = accept(sock->server_fd, (struct sockaddr *)&sock->address, 
                       (socklen_t*)&sock->addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}