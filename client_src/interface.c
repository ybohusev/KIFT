#include "client.h"

void	interface(char const *command, char *answer)
{
	if (*command != 0)
	{
		mvwprintw(mess.mess, 10, 10, "YOU: %s\n", command);
		mvwprintw(mess.mess, 10, 10, "%s\n", answer);
		mvwprintw(mess.mess, 10, 10, "=======================================================\n");
		// printw("\x1b[0m");
		wrefresh(mess.mess);
	}
}
