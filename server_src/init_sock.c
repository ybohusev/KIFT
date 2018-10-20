/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sock.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:04:16 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:04:17 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_sock		init_sock(void)
{
	t_sock		sock;

	sock.addrlen = sizeof(sock.address);
	if ((sock.server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    sock.address.sin_family = AF_INET;
    sock.address.sin_addr.s_addr = INADDR_ANY;
    sock.address.sin_port = htons( PORT );

    if (bind(sock.server_fd, (struct sockaddr *)&sock.address, sizeof(sock.address)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    return (sock);
}
