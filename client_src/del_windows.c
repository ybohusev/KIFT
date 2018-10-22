/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_windows.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:02:37 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:02:45 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	del_windows(t_windows del)
{
	delwin(del.mess.win);
	delwin(del.t.win);
	delwin(del.help.win);
	endwin();
}
