#include "server.h"

cmd		define_command(char *command)
{
    if (!strcmp(command, "SET ALARM") || !strcmp(command, "ALARM"))
        return (set_alarm);
    else if (!strcmp(command, "SET TIMER") || !strcmp(command, "TIMER"))
        return (set_timer);
    else if (!strcmp(command, "TURN ON LIGHTS") || !strcmp(command, "LIGHTS ON"))
        return (lights_on);
    else if (!strcmp(command, "TURN OFF LIGHTS") || !strcmp(command, "LIGHTS OFF"))
        return (lights_off);
    else if (!strcmp(command, "SEND EMAIL") || !strcmp(command, "EMAIL"))
        return (email);
    else if (!strcmp(command, "CHECK EVENTS") || !strcmp(command, "EVENTS"))
        return (events);
    else if (!strcmp(command, "CHECK WEATHER") || !strcmp(command, "WEATHER"))
        return (weather);
    else if (!strcmp(command, "CHECK TRAFFIC") || !strcmp(command, "TRAFFIC"))
	return (check_traffic);
    else if (!strcmp(command, "WHO IS CONNECTED"))
        return (who_connected);
    else if (!strcmp(command, "WHERE IS CONNECTED"))
        return (where_connected);
    else if (!strcmp(command, "PLAY MUSIC") || !strcmp(command, "OPEN PLAYER") || !strcmp(command, "MUSIC"))
        return (music);
    else if (!strcmp(command, "SEARCH THE WEB FOR") || !strcmp(command, "OPEN BROWSER"))
        return (open_browser);
    else if (!strcmp(command, "CLOSE BROWSER"))
        return (close_browser);
    else if (!strcmp(command, "INCREASE BRIGHTNESS"))
        return (inc_bright);
    else if (!strcmp(command, "DECREASE BRIGHTNESS"))
        return (dec_bright);
    else if (!strcmp(command, "INCREASE VOLUME"))
        return (inc_vol);
    else if (!strcmp(command, "DECREASE VOLUME"))
        return (dec_vol);
    else if (!strcmp(command, "SEE LOGS") || !strcmp(command, "SHOW LOGS") || !strcmp(command, "LOGS"))
        return (logs);
    else if (!strcmp(command, "CHECK HISTORY") || !strcmp(command, "SHOW HISTORY") ||
            !strcmp(command, "SEE HISTORY") || !strcmp(command, "HISTORY"))
	    return (check_browser_history);
    else if (!strcmp(command, "PLAY NEXT"))
        return (play_next);
    else if (!strcmp(command, "PLAY PREVIOUS"))
        return (play_prev);
    else if (!strcmp(command, "QUIT ITUNES"))
	return (quit_itunes);
    else if (!strcmp(command, "STOP MUSIC"))
	return (stop_music);
    else if (!strcmp(command, "REMOVE TRASH"))
        return (remove_trash);
    if (!strcmp(command, "MISTER MEESEEKS"))
        return (mees);
    return (nothing);
}
