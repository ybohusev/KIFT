/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:04:11 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:04:13 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void    execute_command(cmd command, char* buffer, int fd, char* answer)
{
	memset(answer, 0, 1024);
    strcpy(answer, command(fd));
    if (mode == DEFAULT)
    	inter_logs(buffer, answer, fd);
    memset(buffer, 0, 1024);
}
