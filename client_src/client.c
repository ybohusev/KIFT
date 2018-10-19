#include "client.h"

int main(int argc, char *argv[])
{
    t_sphinx    sphinx;
    char const  *decoded_speech;
    char       answer[1024];
    int16 buf[2049];

    sphinx = init_sphinx();
    // answer = (char*)malloc(1024);
    while(1)
    {  
      recognize_from_microphone(sphinx.ad, buf);
      send_command(buf, answer);
      // interface(decoded_speech, answer);
      // ad_close(sphinx.ad);
    }
    ad_close(sphinx.ad);
    return (0);
}
