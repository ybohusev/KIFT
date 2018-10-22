/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphinx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:03:32 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:03:34 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_sphinx	init_sphinx(void)
{
	t_sphinx	ret;

	ret.config = cmd_ln_init(NULL, ps_args(), TRUE,
			"-hmm", "./lang_models/en-us-adapt",
			"-lm", "./lang_models/3538.lm",
			"-dict", "./lang_models/3538.dic",
			NULL);
	err_set_logfile("sphinx_log");
	ret.ps = ps_init(ret.config);
	ret.ad = ad_open_dev(NULL, (int32)cmd_ln_float32_r(ret.config,
													"-samprate"));
	return (ret);
}
