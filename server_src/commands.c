#include "server.h"

void	set_alarm(void)
{
    printf("Mr. MEESEEKS: Alarm is ready to set\n");
    system("osascript -e \'say \"Alarm is ready to set\" using \"Victoria\"\'");
}

void	set_timer(void)
{
    printf("Mr. MEESEEKS: Timer is ready to set\n");
    system("osascript -e \'say \"Timer is ready to set\" using \"Victoria\"\'");
}

void	lights_on(void)
{
    printf("Mr. MEESEEKS: Lights is on\n");
    system("osascript -e \'say \"Lights is on\" using \"Victoria\"\'");
}

void	lights_off(void)
{
    printf("Mr. MEESEEKS: Lights is off\n");
    system("osascript -e \'say \"Lights is off\" using \"Victoria\"\'");
}

void	email(void)
{
    printf("Mr. MEESEEKS: Lets send an email\n");
    system("osascript -e \'say \"Lets send an email\" using \"Victoria\"\'");
}

void	events(void)
{
    printf("Mr. MEESEEKS: I'll check your events\n");
    system("osascript -e \'say \"I'll check your events\" using \"Victoria\"\'");
}

void	weather(void)
{
    printf("Mr. MEESEEKS: I'll check weather in your region\n");
    system("osascript -e \'say \"I'll check weather in your region\" using \"Victoria\"\'");
}

void	who_connected(void)
{
    printf("Mr. MEESEEKS: Lets see who is connected\n");
    system("osascript -e \'say \"Lets see who is connected\" using \"Victoria\"\'");
}

void	where_connected(void)
{
    printf("Mr. MEESEEKS: Lets see where we connected\n");
    system("osascript -e \'say \"Lets see where we connected\" using \"Victoria\"\'");
}

void	music(void)
{
    printf("Mr. MEESEEKS: Yeah lets rock\n");
    system("osascript -e \'say \"Yeah lets rock\" using \"Victoria\"\'");
}

void	close_browser(void)
{
    printf("Mr. MEESEEKS: Okey I'll close the browser\n");
    system("osascript -e \'say \"Okey I'll close the browser\" using \"Victoria\"\'");
}

void	inc_bright(void)
{
    printf("Mr. MEESEEKS: Brightness is increased\n");
    system("osascript -e \'say \"Brightness is increased\" using \"Victoria\"\'");
}

void	dec_bright(void)
{
    printf("Mr. MEESEEKS: Brightness is deccreased\n");
    system("osascript -e \'say \"Brightness is deccreased\" using \"Victoria\"\'");
}

void	inc_vol(void)
{
    printf("Mr. MEESEEKS: Volume is increased\n");
    system("osascript -e \'say \"Volume is increased\" using \"Victoria\"\'");
}

void	dec_vol(void)
{
    printf("Mr. MEESEEKS: Volume is decreased\n");
    system("osascript -e \'say \"Volume is decreased\" using \"Victoria\"\'");
}

void	logs(void)
{
    printf("Mr. MEESEEKS: Okey lets see logs\n");
    system("osascript -e \'say \"Okey lets see logs\" using \"Victoria\"\'");
}

void	mees(void)
{
    printf("Mr. MEESEEKS: I'm Mr. Meeseeks! Look at me!\n");
    system("osascript -e \'say \"I'm Mr. Meeseeks! Look at me!\" using \"Victoria\"\'");
}

void	open_browser(void)
{
    printf("Mr. MEESEEKS: Okey I'll open the browser\n");
    system("osascript -e \'say \"Okey I'll open the browser\" using \"Victoria\"\'");
}

void	nothing(void)
{
    printf("Mr. MEESEEKS: Ohhh sorry I dont know how to do it\n");
    system("osascript -e \'say \"Ohhh sorry I dont know how to do it\" using \"Victoria\"\'");
}