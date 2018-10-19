#ifndef CLIENT_H
# define CLIENT_H

#include "common.h"
// #include <pocketsphinx.h>
// #include <sphinxbase/ad.h>
// #include <sphinxbase/err.h>

// typedef struct				s_sphinx
// {
//     ps_decoder_t			*ps;
//     cmd_ln_t				*config;
//     ad_rec_t				*ad;
// }							t_sphinx;

typedef struct				s_sock
{
	struct sockaddr_in		address;
	struct sockaddr_in		serv_addr;
	int						sock;
	int						valread;
	char					buffer[1024];
}							t_sock;

t_sock						init_sock(void);
t_sphinx					init_sphinx(void);
void 						recognize_from_microphone(ad_rec_t *ad, int16 buf[2049]);
int							send_command(int16 buf[2049], char *answer);
void						interface(char const *command, char *answer);

#endif
