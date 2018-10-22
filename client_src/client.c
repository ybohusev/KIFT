/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:01:41 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:01:43 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	main(int argc, char *argv[])
{
	t_sphinx	sphinx;
	char const	*decoded_speech;
	char		answer[1024];
	t_windows	windows;
	t_mess		*l;

	l = NULL;
	windows = init_ncur();
	print_list_commands(windows.t);
	while (1)
	{
		sphinx = init_sphinx();
		decoded_speech = recognize_from_microphone(sphinx.ps,
						sphinx.ad, windows.help);
		send_command(decoded_speech, answer);
		interface(decoded_speech, answer, windows.mess, &l);
		ad_close(sphinx.ad);
	}
	del_all(l);
	del_windows(windows);
	return (0);
}
