#include "server.h"

void    execute_command(cmd command, char* str, int fd)
{
	inter_logs("\x1b[32mYOU: ", str, fd, 1);
    command(fd);
    inter_logs("\x1b[31m", "B========================================D", fd, 0);
    // printf("\x1b[0m");
}