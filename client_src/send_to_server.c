#include "client.h"

int send_command(int16 buf[2049], char *answer)
{
    t_sock  sock;

    memset(answer, 0, 1024);
    // if (decoded_speech != NULL && *decoded_speech != 0)
    // {
        sock = init_sock();  
        if (connect(sock.sock, (struct sockaddr *)&sock.serv_addr,
            sizeof(sock.serv_addr)) < 0)
        {
            printf("\nConnection Failed \n");
            return (-1);
        }
        send(sock.sock, buf, 2049, 0);
        // read(sock.sock, answer, 1024);
    // }
    return (0);
}
