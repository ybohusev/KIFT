#include "server.h"

char*	set_alarm(int fd)
{
    // system("osascript ./scripts/set_alarm.scpt 2>/dev/null");
    // system("osascript -e \'say \"Alarm is ready to set\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Alarm is ready to set");
}

char*	set_timer(int fd)
{
    // system("osascript ./scripts/set_timer.scpt &2>/dev/null \'say\"The timer for 20 seconds is set\" using \"Victoria\"\'");
    // system("osascript -e \'say \"Timer is ready to set\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Timer is ready to set");
}

char*	lights_on(int fd)
{
    // system("osascript ./scripts/lights_on.scpt;");
    // system("osascript -e \'say \"Lights is on\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lights is on");
}

char*	lights_off(int fd)
{
    // system("osascript ./scripts/lights_off.scpt");
    // system("osascript -e \'say \"Lights is of\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lights is off");
}

char*   email(int fd)
{
    // system("osascript ./scripts/email.scpt");
    // system("osascript -e \'say \"Lets send an email\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lets send an email");
}

char*	events(int fd)
{
    // system("osascript ./scripts/events.scpt");
    // system("osascript -e \'say \"I'll check your events\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: I'll check your events");
}

char*	weather(int fd)
{
    // system("osascript ./scripts/weather.scpt");
    // system("osascript -e \'say \"I'll check weather in your region\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: I'll check weather in your region");
}

char*	who_connected(int fd)
{
    // system("osascript -e \'say \"ybohusev is connected\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: ybohusev is connected");
}

char*	where_connected(int fd)
{
    // system("osascript -e \'say \"Lets see where we connected\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Lets see where we connected");
}

char*	music(int fd)
{
    // system("osascript ./scripts/play_music.scpt");
    // system("osascript -e \'say \"Yeah lets rock\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Yeah lets rock");
}

char	*stop_music(int fd)
{
	// system("osascript ./scripts/stop_music.scpt");
    // system("osascript -e \'say \"No more music, MY LORD!\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: No more music, MY LORD!");
}

char	*play_next(int fd)
{
	// system("osascript ./scripts/play_next.scpt");
    // system("osascript -e \'say \"Next track is here, BOSS!\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Next track is here, BOSS!");
}

char    *play_prev(int fd)
{
    // system("osascript ./scripts/play_prev.scpt");
    // system("osascript -e \'say \"Previous track just for you, BOSS!\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Previous track just for you, BOSS!");
}

char	*quit_itunes(int fd)
{
	// system("osascript ./scripts/quit_itunes.scpt");
    // system("osascript -e \'say \"iTunes is dead, BOSS\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: iTunes is dead, BOSS");
}

char*	close_browser(int fd)
{
    // system("osascript ./scripts/close_browser.scpt");
    // system("osascript -e \'say \"Okey I'll close the browser\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Okey I'll close the browser");
}

char*	inc_bright(int fd)
{
    // system("osascript ./scripts/inc_bright.scpt");
    // system("osascript -e \'say \"Brightness is increased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Brightness is increased");
}

char*	dec_bright(int fd)
{
    // system("osascript ./scripts/dec_bright.scpt");
    // system("osascript -e \'say \"Brightness is decreased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Brightness is decreased");  
}

char*	inc_vol(int fd)
{
    // system("osascript ./scripts/increase_volume.scpt");
    // system("osascript -e \'say \"Volume is increased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Volume is increased"); 
}

char*	dec_vol(int fd)
{
    // system("osascript ./scripts/decrease_volume.scpt");
    // system("osascript -e \'say \"Volume is decreased\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Volume is decreased");
}

char*	logs(int fd)
{    
    // system("osascript -e \'say \"Okey lets see logs\" using \"Victoria\"\'");
    // system("open logs");
    return ("Mr. MEESEEKS: Okey lets see logs");
}

char*	mees(int fd)
{
    // system("osascript -e \'say \"I'm Mr. Meeseeks! Look at me!\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: I'm Mr. Meeseeks! Look at me!");
}

char*	open_browser(int fd)
{
    // system("osascript ./scripts/open_browser.scpt");
    return ("Mr. MEESEEKS: Okey I'll open the browser");
}

char*	nothing(int fd)
{
    // system("osascript -e \'say \"Ohhh sorry I dont know how to do it\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: Ohhh sorry I dont know how to do it");
}

char*   remove_trash(int fd)
{
    // system("osascript ./scripts/remove_trash.scpt 2>/dev/null");
    return ("Mr. MEESEEKS: No more trash, boss.");
}

char*   check_browser_history(int fd)
{
    // system("osascript ./scripts/check_browser_history.scpt");
    return ("Mr. MEESEEKS: Here is the history, MY LORD.");
}

char	*check_traffic(int fd)
{
	// system("osascript ./scripts/check_traffic.scpt");
    // system("osascript -e \'say \"Here is the road situation, MY KING!\" using \"Victoria\"\'");
	return ("Mr. MEESEEKS: Here is the road situation, MY KING!");
}

char*           quiet_mode(int fd)
{
    mode = QUIET;
    // system("osascript -e \'say \"quiet mode is on\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: quiet mode is on");
}

char*           default_mode(int fd)
{
    mode = DEFAULT;
    // system("osascript -e \'say \"default mode is on\" using \"Victoria\"\'");
    return ("Mr. MEESEEKS: default mode is on");
}
