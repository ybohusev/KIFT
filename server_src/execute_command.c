#include "server.h"

void    execute_command(cmd command, char* buffer, int fd, char* answer)
{
	memset(answer, 0, 1024);
    strcpy(answer, command(fd));
    if (mode == DEFAULT)
    	inter_logs(buffer, answer, fd);
    memset(buffer, 0, 1024);
}