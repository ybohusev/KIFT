/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:04:02 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:04:03 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static int	draw_comm(t_interface inter)
{
	wattron(inter.win, COLOR_PAIR(4));
	mvwprintw(inter.win, 1, (inter.weight / 2) - 7, "COMMANDS LIST:");
	wattroff(inter.win, COLOR_PAIR(10));
	return (open("commands.txt", O_RDONLY));
}

void		print_list_commands(t_interface inter)
{
	int		fd;
	int		ret;
	char	buf[1];
	char	comm[30];
	int		count;

	count = 0;
	ret = 0;
	fd = draw_comm(inter);
	while ((read(fd, buf, 1)) > 0)
	{
		comm[count] = buf[0];
		if (comm[count] == '\n')
		{
			comm[count] = '\0';
			count = 0;
			mvwprintw(inter.win, ret + 2, (inter.weight / 2) - 7, "%s", comm);
			memset(comm, 0, 30);
			ret++;
		}
		else
			count++;
	}
	wrefresh(inter.win);
	close(fd);
}
