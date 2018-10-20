/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:04:26 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:04:32 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int				main(int argc, char const *argv[])
{
	t_sock		sock;
	char		buffer[1024];
	int			fd;
	char		answer[1024];

	mode = DEFAULT;
	sock = init_sock();
	fd = open("logs", O_CREAT | O_RDWR | O_APPEND, S_IREAD | S_IWRITE);
	while (1)
	{
		listen_client(&sock);
		sock.valread = read(sock.new_socket, buffer, 1024);
		execute_command(define_command(buffer), buffer, fd, answer);
		send(sock.new_socket, answer, strlen(answer), 0);
	}
	close(fd);
	return (0);
}
