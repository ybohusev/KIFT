#include "client.h"

t_sock	init_sock(void)
{
	t_sock	sock;

	sock.sock = 0;
	if ((sock.sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
		printf("\n Socket creation error \n");
		exit(1);
    }
    memset(&sock.serv_addr, '0', sizeof(sock.serv_addr));
    sock.serv_addr.sin_family = AF_INET;
    sock.serv_addr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &sock.serv_addr.sin_addr) <= 0) 
    {
    	printf("\nInvalid address/ Address not supported \n");
    	exit(1);
    }
    return (sock);
}
