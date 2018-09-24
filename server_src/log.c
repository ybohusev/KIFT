#include "server.h"

void	inter_logs(char *str, char *answer, int fd)
{
	time_t		t;
	char* time_m;

	t = time(NULL);
	time_m = (char*)ctime(&t);
	write(fd, time_m, strlen(time_m));
	write(fd, "YOU: ", 5);
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
	write(fd, answer, strlen(answer));
	write(fd, "\n", 1);
	write(fd, "B========================================D\n", 43);
}
