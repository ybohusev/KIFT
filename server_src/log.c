/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsuprun <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 18:04:23 by bsuprun           #+#    #+#             */
/*   Updated: 2018/10/20 18:04:23 by bsuprun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	inter_logs(char *str, char *answer, int fd)
{
	time_t		t;
	char* time_m;

	t = time(NULL);
	time_m = (char*)ctime(&t);
	write(fd, time_m, strlen(time_m));
	write(fd, "YOU: ", 5);
	write(fd, str, strlen(str));
	write(fd, "\n", 1);
	write(fd, answer, strlen(answer));
	write(fd, "\n", 1);
	write(fd, "===================================================\n", 53);
}
