#include "client.h"

int send_command(char const *decoded_speech, char *answer)
{
    t_sock  sock;

    memset(answer, 0, 1024);
    // printf("la;jdgl'f;kh klr;kgefmln\n");
    if (*decoded_speech != 0)
    {
        sock = init_sock();  
        if (connect(sock.sock, (struct sockaddr *)&sock.serv_addr,
            sizeof(sock.serv_addr)) < 0)
        {
            printf("\nConnection Failed \n");
            return (-1);
        }
        send(sock.sock, decoded_speech, strlen(decoded_speech), 0);
        //printf("before\n");
        read(sock.sock, answer, 1024);
        //printf("after\n");
    }
    return (0);
}
