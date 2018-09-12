#include "server.h"

cmd		define_command(char *command)
{
    if (!strcmp(command, "BROWSER"))
        return (open_browser);
    return (nothing);
}
