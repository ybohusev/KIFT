/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listen_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:04:19 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:04:20 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	listen_client(t_sock *sock)
{
    if (listen(sock->server_fd, 3) < 0)
    {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((sock->new_socket = accept(sock->server_fd, (struct sockaddr *)&sock->address, 
                       (socklen_t*)&sock->addrlen))<0)
    {
        perror("accept");
        exit(EXIT_FAILURE);
    }
}
