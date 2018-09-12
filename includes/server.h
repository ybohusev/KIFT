#ifndef SERVER_H
# define SERVER_H

#include "common.h"

typedef void	(* cmd)(void);
typedef struct	sockaddr_in t_sockaddr_in;

cmd				define_command(char *command);
void			execute_command(cmd command);

void			open_browser(void);
void			nothing(void);

#endif