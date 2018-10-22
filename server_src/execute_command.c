/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vonischu <vonischu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:04:11 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/22 15:16:26 by vonischu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	execute_command(t_cmd command, char *buffer, int fd, char *answer)
{
	memset(answer, 0, 1024);
	strcpy(answer, command(fd));
	if (g_mode == DEFAULT)
		inter_logs(buffer, answer, fd);
	memset(buffer, 0, 1024);
}
