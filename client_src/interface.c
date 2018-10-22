/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:03:39 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:03:40 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	change_coords(t_mess *l)
{
	if (l->next == NULL)
		return ;
	while (l->next)
	{
		if (l->next->y < 3)
		{
			del_mess(l->next); 
			l->next = NULL;
			return ;
		}
		l->next->y -= 3;
		l = l->next;
	}
}

static void	print_mess(t_mess *l, t_interface inter)
{
	while (l)
	{
		wattron(inter.win, COLOR_PAIR(2));
		mvwprintw(inter.win, l->y, 2, "YOU: %s", l->you);
		wattroff(inter.win, COLOR_PAIR(10));
		wattron(inter.win, COLOR_PAIR(11));
		mvwprintw(inter.win, l->y + 1, 2, "%s", l->mees);
		wattroff(inter.win, COLOR_PAIR(10));
		wattron(inter.win, COLOR_PAIR(3));
		mvwprintw(inter.win, l->y + 2, 2, "%s", l->del);
		wattroff(inter.win, COLOR_PAIR(10));
		l = l->next;		
	}
}

void		interface(char const *command, char *answer, t_interface inter, t_mess	**l)
{
	if (command != NULL && *command != 0)
	{
		wclear(inter.win);
		wattron(inter.win, COLOR_PAIR(1));
		wborder(inter.win, '|' , '|', '-', '-', '+', '+', '+', '+');
		wattroff(inter.win, COLOR_PAIR(10));
		add_mess(l, (char* const)command, answer, inter);
		change_coords(*l);
		print_mess(*l, inter);
	}
	wrefresh(inter.win);
}
