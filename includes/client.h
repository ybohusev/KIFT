#ifndef CLIENT_H
# define CLIENT_H

#include "common.h"
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>

typedef struct				s_sphinx
{
    ps_decoder_t			*ps;              // create pocketsphinx decoder structure
    cmd_ln_t				*config;          // create configuration structure
    ad_rec_t				*ad;              // create audio recording structure - for use with ALSA functions
}							t_sphinx;

t_sphinx					init_sphinx(void);
const 						char* recognize_from_microphone(ps_decoder_t *ps, ad_rec_t *ad);
int							send_command(char const *decoded_speech);

#endif