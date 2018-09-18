#include "client.h"

int main(int argc, char *argv[])
{
    t_sphinx  sphinx;
    char const *decoded_speech;

    sphinx = init_sphinx();
  
    while(1)
    {                                                           
      decoded_speech = recognize_from_microphone(sphinx.ps, sphinx.ad);       // call the function to capture and decode speech
      send_command(decoded_speech);
    }
    ad_close(sphinx.ad);                                                      // close the microphone
    return (0);
}
