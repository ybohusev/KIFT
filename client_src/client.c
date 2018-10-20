#include "client.h"

t_mess        new_mess(char *you, char *mees)
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
    return (tmp);
}

void    add_mess(t_mess *mess, char *you, char *mees)
{
    t_mess
}

void  init_ncur()
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
    init_pair(10, COLOR_MAGENTA, COLOR_BLACK);
    mess.height = 66;
    mess.weight = 110;
    mess.cur_height = 62;
    mess.cur_weight = 2;
    mess.mess = newwin(mess.height, mess.weight, 0, 0);
    wattron(mess.mess, COLOR_PAIR(1));
    wborder(mess.mess, '|' , '|', '-', '-', '+', '+', '+', '+');
    wattroff(mess.mess, COLOR_PAIR(10));
    wrefresh(mess.mess);
}

int main(int argc, char *argv[])
{
    t_sphinx    sphinx;
    char const  *decoded_speech;
    char        answer[1024];
    t_mess      *mess;

    init_ncur();
    mvwprintw(mess.mess, mess.cur_height++, mess.cur_weight, "YOU: ");
    mvwprintw(mess.mess, mess.cur_height++, mess.cur_weight, "MEESEEKS: ");
    mvwprintw(mess.mess, mess.cur_height++, mess.cur_weight, "=======================================================");
    wrefresh(mess.mess);
    while (1);
    delwin(mess.mess);
    endwin();


    // while(1)
    // {
    //   sphinx = init_sphinx();  
    //   decoded_speech = recognize_from_microphone(sphinx.ps, sphinx.ad);
    //   send_command(decoded_speech, answer);
    //   interface(decoded_speech, answer);
    //   ad_close(sphinx.ad);
    // }
    return (0);
}
