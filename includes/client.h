#ifndef CLIENT_H
# define CLIENT_H

#include "common.h"
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>

typedef struct				s_sphinx
{
    ps_decoder_t			*ps;
    cmd_ln_t				*config;
    ad_rec_t				*ad;
}							t_sphinx;

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
const 						char* recognize_from_microphone(ps_decoder_t *ps, ad_rec_t *ad);
int							send_command(char const *decoded_speech);
void						interface(char const *command);

#endif