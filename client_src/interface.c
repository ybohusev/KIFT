#include "client.h"

void	interface(char const *command)
{
	if (*command != 0)
	{
		printf("\x1b[32mYOU: %s\n", command);
		printf("\x1b[31mB========================================D\n");
		printf("\x1b[0m");
	}
}
