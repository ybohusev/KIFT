// Server side C/C++ program to demonstrate Socket programming
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

typedef void (* cmd)(void);

static void    ft_strclr(char s[])
{
    int i;

    i = 0;
    while (i < 1024)
        s[i++] = 0;
}

/************************command implementation******************/

void    open_browser(void)
{
    printf("Open Browser\n");
    // char *str = "osascript -e \'open location \"http://www.google.com\"\'";
    // system(str);
}

void    nothing(void)
{
    printf("unknown command\n");
}

/************************command recognation*********************/

cmd     define_command(char *command)
{
    if (!strcmp(command, "BROWSER"))
        return (open_browser);
    return (nothing);
}
void    execute_command(cmd command)
{
    command();
}

/****************************************************************/
int main(int argc, char const *argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char cmd[1024] = {0};
    char *hello = "Hello from server";
      
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
    if (bind(server_fd, (struct sockaddr *)&address, 
                                 sizeof(address))<0)
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
            printf("%s\n",buffer );
            execute_command(define_command(buffer));
            // sprintf(cmd, "osascript -e \'say \"%s\" using \"Victoria\"\'", buffer);
            // system(cmd);
            ft_strclr(buffer);
    }
    send(new_socket , hello , strlen(hello) , 0 );
    printf("Hello message sent\n");

    // char buffer[1024] = {0};
    // execute_command(define_command(buffer));
    return 0;
}