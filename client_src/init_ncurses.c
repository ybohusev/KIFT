/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ncurses.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:03:08 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:03:09 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	init_std(void)
{
	initscr();
	noecho();
	curs_set(0);
	start_color();
	init_color(COLOR_MAGENTA, 500, 500, 500);
	init_pair(1, COLOR_GREEN, COLOR_GREEN);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_MAGENTA);
	init_pair(6, COLOR_BLACK, COLOR_GREEN);
	init_pair(7, COLOR_BLACK, COLOR_BLUE);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	init_pair(9, COLOR_BLACK, COLOR_CYAN);
	init_pair(11, COLOR_YELLOW, COLOR_BLACK);
	init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
}

static void	draw_bord(t_interface inter)
{
	wattron(inter.win, COLOR_PAIR(1));
	wborder(inter.win, '|', '|', '-', '-', '+', '+', '+', '+');
	wattroff(inter.win, COLOR_PAIR(10));
	wrefresh(inter.win);
}

t_windows	init_ncur(void)
{
	t_windows		windows;
	struct winsize	w;

	init_std();
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	windows.mess.weight = w.ws_col / 1.25;
	windows.t.weight = w.ws_col - windows.mess.weight;
	windows.help.weight = windows.mess.weight;
	windows.mess.height = w.ws_row - 2;
	windows.t.height = w.ws_row;
	windows.help.height = 3;
	windows.mess.win = newwin(windows.mess.height, windows.mess.weight, 2, 0);
	windows.t.win = newwin(windows.t.height, windows.t.weight,
						0, windows.mess.weight);
	windows.help.win = newwin(windows.help.height, windows.help.weight, 0, 0);
	draw_bord(windows.help);
	draw_bord(windows.mess);
	draw_bord(windows.t);
	return (windows);
}
