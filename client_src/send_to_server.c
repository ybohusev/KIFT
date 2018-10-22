/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_to_server.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:04:11 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:04:14 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

int	send_command(char const *decoded_speech, char *answer)
{
	t_sock	sock;

	memset(answer, 0, 1024);
	if (decoded_speech != NULL && *decoded_speech != 0)
	{
		sock = init_sock();
		if (connect(sock.sock, (struct sockaddr *)&sock.serv_addr,
			sizeof(sock.serv_addr)) < 0)
		{
			printf("\nConnection Failed \n");
			return (-1);
		}
		send(sock.sock, decoded_speech, strlen(decoded_speech), 0);
		read(sock.sock, answer, 1024);
	}
	return (0);
}
