char	*party(int fd)
{
    system("osascript -e \'say \"Lets start the party!!!\" \
            using \"Victoria\"\'");
    system("osascript ./scripts/party.scpt &>/dev/null");
    return ("Mr. MEESEEKS: Lets start the party!!!");
}

char    *joke(int fd)
{
    system("osascript -e \'say \"We will conquer the world\" \
            using \"Victoria\"\'");
    system("osascript ./scripts/joke.scpt &>/dev/null");
    return ("Mr. MEESEEKS: WE WILL CONQUER THE WORLD!");
}

char    *open_terminal(int fd)
{
    system("osascript -e \'say \"Terminal is ready\" \
            using \"Victoria\"\'");
    system("osascript ./scripts/open_terminal.scpt &>/dev/null");
    return ("Mr. MEESEEKS: Terminal is ready, MY LORD!");
}
