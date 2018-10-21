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
    tmp->del = "=======================================================";
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

void	change_coords(t_mess *l)
{
	if (l->next == NULL)
		return ;
	while (l->next)
	{
		l->next->y -= 3;
		l = l->next;
	}
}

void	print_mess(t_mess *l)
{
	while (l)
	{
		mvwprintw(mess.mess, l->y, 2, "YOU: %s", l->you);
		mvwprintw(mess.mess, l->y + 1, 2, "%s", l->mees);
		mvwprintw(mess.mess, l->y + 2, 2, "%s", l->del);
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
