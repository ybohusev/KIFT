#include "client.h"

t_mess        *new_mess(char *you, char *mees)
{
    t_mess  *tmp;

    tmp = (t_mess*)malloc(sizeof(t_mess));

    tmp->you = (char*)malloc(strlen(you) + 1);
    tmp->you[strlen(you)] = '\0';
    strcpy(tmp->you, you);
    tmp->mees = (char*)malloc(strlen(mees) + 1);
    tmp->mees[strlen(mees)] = '\0';
    strcpy(tmp->mees, mees);
    tmp->del = (char*)malloc(mess.weight - 4 + 1);
    tmp->del[mess.weight - 4] = '\0';
    memset(tmp->del, '=', mess.weight - 4);
    tmp->x = 2;
    tmp->y = mess.height - 4;
    tmp->next = NULL;
    return (tmp);
}

void    add_mess(t_mess **l, char *you, char *mees)
{
	t_mess	*tmp;

	tmp = new_mess(you, mees);
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

void	change_coords(t_mess *l)
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

void	print_mess(t_mess *l)
{
	while (l)
	{
		wattron(mess.mess, COLOR_PAIR(2));
		mvwprintw(mess.mess, l->y, 2, "YOU: %s", l->you);
		wattroff(mess.mess, COLOR_PAIR(10));
		wattron(mess.mess, COLOR_PAIR(11));
		mvwprintw(mess.mess, l->y + 1, 2, "%s", l->mees);
		wattroff(mess.mess, COLOR_PAIR(10));
		wattron(mess.mess, COLOR_PAIR(3));
		mvwprintw(mess.mess, l->y + 2, 2, "%s", l->del);
		wattroff(mess.mess, COLOR_PAIR(10));
		l = l->next;		
	}
}

void	interface(char const *command, char *answer, t_mess **l)
{
	if (command != NULL && *command != 0)
	{
		wclear(mess.mess);
		wattron(mess.mess, COLOR_PAIR(1));
    	wborder(mess.mess, '|' , '|', '-', '-', '+', '+', '+', '+');
    	wattroff(mess.mess, COLOR_PAIR(10));
		add_mess(l, (char* const)command, answer);
		change_coords(*l);
		print_mess(*l);
	}
	wrefresh(mess.mess);
}
