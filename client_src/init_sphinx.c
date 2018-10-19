#include "client.h"

t_sphinx	init_sphinx(void)
{
	t_sphinx	ret;

	// ret.config = cmd_ln_init(NULL, ps_args(), TRUE,
 //             "-hmm", "./lang_models/en-us-adapt",
 //             "-lm", "./lang_models/3538.lm.bin",
 //             "-dict",  "./lang_models/3538.dict",
 //             NULL);
	// err_set_logfile("sphinx_log");
 //    ret.ps = ps_init(ret.config);
    // ret.ad = ad_open_dev("sysdefault", (int32) cmd_ln_float32_r(ret.config, "-samprate"));
    // printf("%f\n", cmd_ln_float32_r(ret.config, "-samprate"));

    ret.ad = ad_open_sps(16000);
    return (ret);
}
