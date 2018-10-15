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
    system("osascript ./scripts/lights_on.scpt");
    return ("Mr. MEESEEKS: Lights is on");
}

char*	lights_off(int fd)
{
    system("osascript ./scripts/lights_off.scpt");
    return ("Mr. MEESEEKS: Lights is off");
}

char*   email(int fd)
{
    system("osascript ./scripts/email.scpt");
    return ("Mr. MEESEEKS: Lets send an email");
}

char*	events(int fd)
{
    system("osascript ./scripts/events.scpt");
    return ("Mr. MEESEEKS: I'll check your events");
}

char*	weather(int fd)
{
    system("osascript ./scripts/weather.scpt");
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
    system("osascript ./scripts/close_browser.scpt");
    return ("Mr. MEESEEKS: Okey I'll close the browser");
}

char*	inc_bright(int fd)
{
    system("osascript ./scripts/inc_bright.scpt");
    return ("Mr. MEESEEKS: Brightness is increased");
}

char*	dec_bright(int fd)
{
    system("osascript ./scripts/dec_bright.scpt");
    return ("Mr. MEESEEKS: Brightness is decreased");  
}

char*	inc_vol(int fd)
{
    system("osascript ./scripts/increase_volume.scpt");
    return ("Mr. MEESEEKS: Volume is increased"); 
}

char*	dec_vol(int fd)
{
    system("osascript ./scripts/decrease_volume.scpt");
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
    system("osascript ./scripts/open_browser.scpt");
    return ("Mr. MEESEEKS: Okey I'll open the browser");
}

char*	nothing(int fd)
{
    system("osascript -e \'say \"Ohhh sorry I dont know how to do it\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Ohhh sorry I dont know how to do it");
}

char*   remove_trash(int fd)
{
    system("osascript ./scripts/remove_trash.scpt");
    return ("Mr. MEESEEKS: No more trash, boss.");
}

char*   check_browser_history(int fd)
{
    system("osascript ./scripts/check_browser_history.scpt");
    return ("Mr. MEESEEKS: Here is the history, MY LORD.");
}