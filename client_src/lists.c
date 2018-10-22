/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybohusev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 14:03:46 by ybohusev          #+#    #+#             */
/*   Updated: 2018/10/22 14:03:47 by ybohusev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

t_mess	*new_mess(char *you, char *mees, t_interface inter)
{
	t_mess	*tmp;

	tmp = (t_mess*)malloc(sizeof(t_mess));
	tmp->you = (char*)malloc(strlen(you) + 1);
	tmp->you[strlen(you)] = '\0';
	strcpy(tmp->you, you);
	tmp->mees = (char*)malloc(strlen(mees) + 1);
	tmp->mees[strlen(mees)] = '\0';
	strcpy(tmp->mees, mees);
	tmp->del = (char*)malloc(inter.weight - 4 + 1);
	tmp->del[inter.weight - 4] = '\0';
	memset(tmp->del, '=', inter.weight - 4);
	tmp->x = 2;
	tmp->y = inter.height - 4;
	tmp->next = NULL;
	return (tmp);
}

void	add_mess(t_mess **l, char *you, char *mees, t_interface inter)
{
	t_mess	*tmp;

	tmp = new_mess(you, mees, inter);
	if (*l == NULL)
	{
		*l = tmp;
		return ;
	}
	tmp->next = *l;
	*l = tmp;
}

void	del_mess(t_mess *l)
{
	free(l->you);
	free(l->mees);
	free(l->del);
	free(l);
	l = NULL;
}

void	del_all(t_mess *l)
{
	t_mess	*tmp;

	tmp = l;
	while (l)
	{
		l = l->next;
		del_mess(tmp);
		tmp = NULL;
	}
	l = NULL;
}
