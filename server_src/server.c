#include "server.h"

/****************************************************************/
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    t_sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char cmd[1024] = {0};
    int fd;
    
    fd = open("logs", O_CREAT | O_RDWR | O_APPEND, S_IREAD | S_IWRITE);  
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons( PORT );
      
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    while (1)
     {
        if (listen(server_fd, 3) < 0)
        {
            perror("listen");
            exit(EXIT_FAILURE);
        }
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
                           (socklen_t*)&addrlen))<0)
        {
            perror("accept");
            exit(EXIT_FAILURE);
        }
            valread = read( new_socket , buffer, 1024);
            execute_command(define_command(buffer), buffer, fd);
            memset(buffer, 0, 1024);
    }
    close(fd);
    return 0;
}