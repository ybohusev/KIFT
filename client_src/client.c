#include "client.h"
#include <sys/ioctl.h>

void  init_ncur()
{
    struct winsize w;
    
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
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

    mess.weight = w.ws_col / 1.25;
    t.weight = w.ws_col - mess.weight;
    help.weight = mess.weight;

    mess.height = w.ws_row - 2;
    t.height = w.ws_row;
    help.height = 3;
    
    mess.mess = newwin(mess.height, mess.weight, 2, 0);
    t.mess = newwin(t.height, t.weight, 0, mess.weight);
    help.mess = newwin(help.height, help.weight, 0, 0);
    
    wattron(help.mess, COLOR_PAIR(1));
    wborder(help.mess, '|' , '|', '-', '-', '+', '+', '+', '+');
    wattroff(help.mess, COLOR_PAIR(10));
    wrefresh(help.mess);

    
    wattron(mess.mess, COLOR_PAIR(1));
    wborder(mess.mess, '|' , '|', '-', '-', '+', '+', '+', '+');
    wattroff(mess.mess, COLOR_PAIR(10));
    wrefresh(mess.mess);
    
    wattron(t.mess, COLOR_PAIR(1));
    wborder(t.mess, '|' , '|', '-', '-', '+', '+', '+', '+');
    wattroff(t.mess, COLOR_PAIR(10));
    wrefresh(t.mess);
}

void    print_list_commands(void)
{
    int     fd;
    int     ret;
    char    buf[1];
    char    comm[30];
    int     count;

    count = 0;
    ret = 0;
    wattron(t.mess, COLOR_PAIR(4));
    mvwprintw(t.mess, 1, (t.weight / 2) - 7, "COMMANDS LIST:");
    wattroff(t.mess, COLOR_PAIR(10));
    fd = open("commands.txt", O_RDONLY);
    while ((read(fd, buf, 1)) > 0)
    {
        comm[count] = buf[0];
        if (comm[count] == '\n')
        {
            comm[count] = '\0';
            count = 0;
            mvwprintw(t.mess, ret + 2, (t.weight / 2) - 7, "%s", comm);
            memset(comm, 0, 30);
            ret++;
        }
        else
            count++;
    }
    wrefresh(t.mess);
    close(fd);
}

int main(int argc, char *argv[])
{
    t_sphinx    sphinx;
    char const  *decoded_speech;
    char        answer[1024];
    t_mess      *l;

    init_ncur();
    l = NULL;
    print_list_commands();
    while(1)
    {
      sphinx = init_sphinx();  
      decoded_speech = recognize_from_microphone(sphinx.ps, sphinx.ad);
      send_command(decoded_speech, answer);
      interface(decoded_speech, answer, &l);
      ad_close(sphinx.ad);
    }
    delwin(mess.mess);
    endwin();
    return (0);
}
