#ifndef SERVER_H
# define SERVER_H

#include "common.h"

typedef void	(* cmd)(void);
typedef struct	sockaddr_in t_sockaddr_in;

cmd				define_command(char *command);
void			execute_command(cmd command, char *str);

void			open_browser(void);
void			nothing(void);
void			set_alarm(void);
void			set_timer(void);
void			lights_on(void);
void			lights_off(void);
void			email(void);
void			events(void);
void			weather(void);
void			who_connected(void);
void			where_connected(void);
void			music(void);
void			close_browser(void);
void			inc_bright(void);
void			dec_bright(void);
void			inc_vol(void);
void			dec_vol(void);
void			logs(void);
void			mees(void);

#endif