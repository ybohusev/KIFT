#include "server.h"

char*    execute_command(cmd command, char* str, int fd, char* answer)
{
	memset(answer, 0, 1024);
    strcpy(answer, command(fd));
    inter_logs(str, answer, fd);
    return(answer);
}