#include "server.h"

void    execute_command(cmd command, char* str)
{
	printf("\x1b[32mYOU: %s\n", str);
	printf("\x1b[33m");
    command();
    printf("\x1b[31mB========================================D\x1b[0m\n");
}