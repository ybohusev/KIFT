#ifndef COMMON_H
# define COMMON_H

# include <unistd.h>
# include <stdio.h>
# include <sys/socket.h>
# include <stdlib.h>
# include <netinet/in.h>
# include <string.h>
# include <arpa/inet.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>


#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>

# define PORT 8080


typedef struct				s_sphinx
{
    ps_decoder_t			*ps;
    cmd_ln_t				*config;
    ad_rec_t				*ad;
}							t_sphinx;

#endif