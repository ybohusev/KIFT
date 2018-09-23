#include "server.h"

void	set_alarm(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Alarm is ready to set", fd, 0);
    system("osascript -e \'say \"Alarm is ready to set\" using \"Victoria\"\'");
}

void	set_timer(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Timer is ready to set", fd, 0);
    system("osascript -e \'say \"Timer is ready to set\" using \"Victoria\"\'");
}

void	lights_on(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Lights is on", fd, 0);
    system("osascript -e \'say \"Lights is on\" using \"Victoria\"\'");
}

void	lights_off(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Lights is off", fd, 0);
    system("osascript -e \'say \"Lights is off\" using \"Victoria\"\'");
}

void	email(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Lets send an email", fd, 0);
    system("osascript -e \'say \"Lets send an email\" using \"Victoria\"\'");
}

void	events(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: I'll check your events", fd, 0);
    system("osascript -e \'say \"I'll check your events\" using \"Victoria\"\'");
}

void	weather(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: I'll check weather in your region", fd, 0);
    system("osascript -e \'say \"I'll check weather in your region\" using \"Victoria\"\'");
}

void	who_connected(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Lets see who is connected", fd, 0);
    system("osascript -e \'say \"Lets see who is connected\" using \"Victoria\"\'");
}

void	where_connected(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Lets see where we connected", fd, 0);
    system("osascript -e \'say \"Lets see where we connected\" using \"Victoria\"\'");
}

void	music(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Yeah lets rock", fd, 0);
    system("osascript -e \'say \"Yeah lets rock\" using \"Victoria\"\'");
}

void	close_browser(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Okey I'll close the browser", fd, 0);
    system("osascript -e \'say \"Okey I'll close the browser\" using \"Victoria\"\'");
}

void	inc_bright(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Brightness is increased", fd, 0);
    system("osascript -e \'say \"Brightness is increased\" using \"Victoria\"\'");
}

void	dec_bright(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Brightness is deccreased", fd, 0);
    system("osascript -e \'say \"Brightness is deccreased\" using \"Victoria\"\'");
}

void	inc_vol(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Volume is increased", fd, 0);
    system("osascript -e \'say \"Volume is increased\" using \"Victoria\"\'");
}

void	dec_vol(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Volume is decreased", fd, 0);
    system("osascript -e \'say \"Volume is decreased\" using \"Victoria\"\'");
}

void	logs(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Okey lets see logs", fd, 0);
    system("osascript -e \'say \"Okey lets see logs\" using \"Victoria\"\'");
    system("cat log");
}

void	mees(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: I'm Mr. Meeseeks! Look at me!", fd, 0);
    system("osascript -e \'say \"I'm Mr. Meeseeks! Look at me!\" using \"Victoria\"\'");
}

void	open_browser(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Okey I'll open the browser", fd, 0);
    system("osascript -e \'say \"Okey I'll open the browser\" using \"Victoria\"\'");
}

void	nothing(int fd)
{
    inter_logs("\x1b[33m", "Mr. MEESEEKS: Ohhh sorry I dont know how to do it", fd, 0);
    system("osascript -e \'say \"Ohhh sorry I dont know how to do it\" using \"Victoria\"\'");
}