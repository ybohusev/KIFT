#include <stdio.h>
#include <string.h>
#include <pocketsphinx.h>
#include <sphinxbase/ad.h>
#include <sphinxbase/err.h>

#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#define PORT 8080

const char * recognize_from_microphone();

int send_command(char const *decoded_speech)
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
    // Convert IPv4 and IPv6 addresses from text to binary form
    if(inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)<=0) 
    {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }
    if (*decoded_speech != 0)
    {  
      if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
      {
          printf("\nConnection Failed \n");
          return -1;
      }
      send(sock, decoded_speech, strlen(decoded_speech), 0);
      printf("Hello message sent\n");
    }
    // valread = read( sock , buffer, 1024);
    // printf("%s\n",buffer );
    return 0;
}

/*****************************************************************************************/
ps_decoder_t *ps;                  // create pocketsphinx decoder structure
cmd_ln_t *config;                  // create configuration structure
ad_rec_t *ad;                      // create audio recording structure - for use with ALSA functions

int16 adbuf[4096];                 // buffer array to hold audio data
uint8 utt_started, in_speech;      // flags for tracking active speech - has speech started? - is speech currently happening?
int32 k;                           // holds the number of frames in the audio buffer
char const *hyp;                   // pointer to "hypothesis" (best guess at the decoded result)
char const *decoded_speech;

/****************************************************************************************/
int main(int argc, char *argv[]) {

config = cmd_ln_init(NULL, ps_args(), TRUE,
          "-hmm", MODELDIR "/en-us/en-us",
          "-lm",  "./lang_models/assistant.lm",
          "-dict", "./lang_models/assistant.dic",
          NULL);

   // config = cmd_ln_init(NULL, ps_args(), TRUE,
   //           "-hmm", MODELDIR "/en-us/en-us",
   //                 "-lm", MODELDIR "/en-us/en-us.lm.bin",
   //                 "-dict", MODELDIR "/en-us/cmudict-en-us.dict",
   //                 NULL);
  ps = ps_init(config);                                                // initialize the pocketsphinx decoder
  ad = ad_open_dev("sysdefault", (int32) cmd_ln_float32_r(config, "-samprate")); // open default microphone at default samplerate
  while(1){                                                           
    decoded_speech = recognize_from_microphone();       // call the function to capture and decode speech           
    printf("You Said: *%s*\n", decoded_speech);      // send decoded speech to screen
    send_command(decoded_speech);
   }

 ad_close(ad);                                                    // close the microphone
}

/*****************************************************************************************/
const char * recognize_from_microphone(){

    ad_start_rec(ad);                                // start recording
    ps_start_utt(ps);                                // mark the start of the utterance
    utt_started = FALSE;                             // clear the utt_started flag

    while(1) {                                       
        k = ad_read(ad, adbuf, 4096);                // capture the number of frames in the audio buffer
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder

        in_speech = ps_get_in_speech(ps);            // test to see if speech is being detected

        if (in_speech && !utt_started) {             // if speech has started and utt_started flag is false                            
            utt_started = TRUE;                      // then set the flag
        }
 
        if (!in_speech && utt_started) {             // if speech has ended and the utt_started flag is true 
            ps_end_utt(ps);                          // then mark the end of the utterance
            ad_stop_rec(ad);                         // stop recording
            hyp = ps_get_hyp(ps, NULL );             // query pocketsphinx for "hypothesis" of decoded statement
            return hyp;                              // the function returns the hypothesis
            break;                                   // exit the while loop and return to main
        }
    }

}
