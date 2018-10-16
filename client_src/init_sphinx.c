#include "client.h"

t_sphinx	init_sphinx(void)
{
	t_sphinx	ret;

	ret.config = cmd_ln_init(NULL, ps_args(), TRUE,
             "-hmm", MODELDIR "/en-us/en-us",
             "-lm", "./lang_models/meeseeks_model.lm.bin",
             "-dict",  "./lang_models/meeseeks_model.dict",
             NULL);
	err_set_logfile("sphinx_log");
    ret.ps = ps_init(ret.config);
    ret.ad = ad_open_dev("sysdefault", (int32) cmd_ln_float32_r(ret.config, "-samprate"));
    return (ret);
}
