#include "client.h"

int send_command(char const *decoded_speech)
{
    t_sock  sock;

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
    }
    return 0;
}
