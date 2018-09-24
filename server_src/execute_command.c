#include "server.h"

void    execute_command(cmd command, char* str, int fd)
{
	char buffer[1024] = {0};

    strcpy(buffer, command(fd));
    inter_logs(str, buffer, fd);
}