#include "client.h"

int main(int argc, char *argv[])
{
    t_sphinx    sphinx;
    char const  *decoded_speech;
    char*       answer;

    sphinx = init_sphinx();
    answer = (char*)malloc(1024);
    while(1)
    {                                                           
      decoded_speech = recognize_from_microphone(sphinx.ps, sphinx.ad);
      send_command(decoded_speech, answer);
      interface(decoded_speech, answer);
    }
    free(answer);
    ad_close(sphinx.ad);
    return (0);
}
