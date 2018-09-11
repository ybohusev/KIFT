#include "client.h"

t_sphinx	init_sphinx(void)
{
	t_sphinx	ret;

	ret.config = cmd_ln_init(NULL, ps_args(), TRUE,
             "-hmm", MODELDIR "/en-us/en-us",
             "-lm", MODELDIR "/en-us/en-us.lm.bin",
             "-dict", MODELDIR "/en-us/cmudict-en-us.dict",
             NULL);
    ret.ps = ps_init(ret.config);                                                // initialize the pocketsphinx decoder
    ret.ad = ad_open_dev(NULL, (int32) cmd_ln_float32_r(ret.config, "-samprate")); // open default microphone at default samplerate
    return (ret);
}
