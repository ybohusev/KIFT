/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mic.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:03:52 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:03:55 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void			print_help(t_interface help, char *str)
{
	wclear(help.win);
	wattron(help.win, COLOR_PAIR(1));
	wborder(help.win, '|' , '|', '-', '-', '+', '+', '+', '+');
	wattroff(help.win, COLOR_PAIR(10));
	mvwprintw(help.win, 1, 1, "%s", str);
	wrefresh(help.win);
}

static const char	*recogn(ps_decoder_t *ps, int32 k, t_interface help)
{
	char const	*hyp;

	ps_end_utt(ps);
	hyp = ps_get_hyp(ps, &k);
	print_help(help, "PROCESSING...");
	return (hyp);
}

const char			*recognize_from_microphone(ps_decoder_t *ps, ad_rec_t *ad, t_interface help)
{
	int16 adbuf[4096];
	uint8 cur_vad_state;
	uint8 vad_state;
	int32 k;
	char const *hyp;

	if (ad_start_rec(ad) < 0)
		E_FATAL("FAILED TO START RECORDING\n");
	if (ps_start_utt(ps) < 0)
		E_FATAL("FAILED TO START UTTERANCE\n");
	cur_vad_state = 0;
	while (1)
	{
		if ((k = ad_read(ad, adbuf, 4096)) < 0)
			return (NULL);
		ps_process_raw(ps, adbuf, k, FALSE, FALSE);
		vad_state = ps_get_in_speech(ps);
		if (vad_state && !cur_vad_state)
			print_help(help, "LISTENING...");
		if (!vad_state && cur_vad_state)
			return (recogn(ps, k, help));
		cur_vad_state = vad_state;
	}
}
