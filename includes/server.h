#ifndef SERVER_H
# define SERVER_H

#include "common.h"

typedef char*	(* cmd)(int);
typedef struct	sockaddr_in t_sockaddr_in;

cmd				define_command(char *command);
void			execute_command(cmd command, char *str, int fd);
void			inter_logs(char *str, char *answer, int fd);

char*			open_browser(int fd);
char*			nothing(int fd);
char*			set_alarm(int fd);
char*			set_timer(int fd);
char*			lights_on(int fd);
char*			lights_off(int fd);
char*			email(int fd);
char*			events(int fd);
char*			weather(int fd);
char*			who_connected(int fd);
char*			where_connected(int fd);
char*			music(int fd);
char*			close_browser(int fd);
char*			inc_bright(int fd);
char*			dec_bright(int fd);
char*			inc_vol(int fd);
char*			dec_vol(int fd);
char*			logs(int fd);
char*			mees(int fd);
char*   		check_browser_history(int fd);
char*   		remove_trash(int fd);

#endif