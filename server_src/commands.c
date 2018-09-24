#include "server.h"

char*	set_alarm(int fd)
{
    system("osascript -e \'say \"Alarm is ready to set\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Alarm is ready to set");
}

char*	set_timer(int fd)
{
    system("osascript -e \'say \"Timer is ready to set\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Timer is ready to set");
}

char*	lights_on(int fd)
{
    system("osascript -e \'say \"Lights is on\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lights is on");
}

char*	lights_off(int fd)
{
    system("osascript -e \'say \"Lights is off\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lights is off");
}

char*   email(int fd)
{
    system("osascript -e \'say \"Lets send an email\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lets send an email");
}

char*	events(int fd)
{
    system("osascript -e \'say \"I'll check your events\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: I'll check your events");
}

char*	weather(int fd)
{
    system("osascript -e \'say \"I'll check weather in your region\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: I'll check weather in your region");
}

char*	who_connected(int fd)
{
    system("osascript -e \'say \"Lets see who is connected\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lets see who is connected");
}

char*	where_connected(int fd)
{
    system("osascript -e \'say \"Lets see where we connected\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lets see where we connected");
}

char*	music(int fd)
{
    system("osascript -e \'say \"Yeah lets rock\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Yeah lets rock");
}

char*	close_browser(int fd)
{
    system("osascript -e \'say \"Okey I'll close the browser\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Okey I'll close the browser");
}

char*	inc_bright(int fd)
{
    system("osascript -e \'say \"Brightness is increased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Brightness is increased");
}

char*	dec_bright(int fd)
{
    system("osascript -e \'say \"Brightness is deccreased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Brightness is deccreased");  
}

char*	inc_vol(int fd)
{
    system("osascript -e \'say \"Volume is increased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Volume is increased"); 
}

char*	dec_vol(int fd)
{
    system("osascript -e \'say \"Volume is decreased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Volume is decreased");
}

char*	logs(int fd)
{    
    system("osascript -e \'say \"Okey lets see logs\" using \"Victoria\"\'");
    system("cat log");
    return ("Mr. MEESEEKS: Okey lets see logs");
}

char*	mees(int fd)
{
    system("osascript -e \'say \"I'm Mr. Meeseeks! Look at me!\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: I'm Mr. Meeseeks! Look at me!");
}

char*	open_browser(int fd)
{
    system("osascript -e \'say \"Okey I'll open the browser\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Okey I'll open the browser");
}

char*	nothing(int fd)
{
    system("osascript -e \'say \"Ohhh sorry I dont know how to do it\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Ohhh sorry I dont know how to do it");
}