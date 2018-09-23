#include "server.h"

void	inter_logs(char *color, char *str, int fd, int flag)
{
	time_t		t;
	char* time_m;

	t = time(NULL);
	time_m = (char*)ctime(&t);
	if (flag == 1)
	{
		write(fd, "\n", 1);
		write(fd, time_m, strlen(time_m));
	}
	printf("%s%s\n", color, str);
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
}
