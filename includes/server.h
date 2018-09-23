#ifndef SERVER_H
# define SERVER_H

#include "common.h"

typedef void	(* cmd)(int);
typedef struct	sockaddr_in t_sockaddr_in;

cmd				define_command(char *command);
void			execute_command(cmd command, char *str, int fd);
void			inter_logs(char *color, char *str, int fd, int flag);

void			open_browser(int fd);
void			nothing(int fd);
void			set_alarm(int fd);
void			set_timer(int fd);
void			lights_on(int fd);
void			lights_off(int fd);
void			email(int fd);
void			events(int fd);
void			weather(int fd);
void			who_connected(int fd);
void			where_connected(int fd);
void			music(int fd);
void			close_browser(int fd);
void			inc_bright(int fd);
void			dec_bright(int fd);
void			inc_vol(int fd);
void			dec_vol(int fd);
void			logs(int fd);
void			mees(int fd);

#endif