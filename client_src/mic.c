#include "client.h"

const char * recognize_from_microphone(ps_decoder_t *ps, ad_rec_t *ad)
{
    int16 adbuf[4096];                               // buffer array to hold audio data
    uint8 utt_started;                               // flags for tracking active speech - has speech started?
    uint8 in_speech;                                 //- is speech currently happening?
    int32 k;                                         // holds the number of frames in the audio buffer
    char const *hyp;                                 // pointer to "hypothesis" (best guess at the decoded result)

    ad_start_rec(ad);                                // start recording
    ps_start_utt(ps);                                // mark the start of the utterance
    utt_started = FALSE;                             // clear the utt_started flag

    int d = 0;
    while(1)
    {
                                      
        if ((k = ad_read(ad, adbuf, 4096)) < 0)      // capture the number of frames in the audio buffer
        {
            printf("ERROR READ K\n");
            return (NULL);
        }
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder
        in_speech = ps_get_in_speech(ps);            // test to see if speech is being detected
        if (in_speech && !utt_started)               // if speech has started and utt_started flag is false
        {
            utt_started = TRUE;
        }
        if (!in_speech && utt_started)
        {                                            // if speech has ended and the utt_started flag is true 
            ps_end_utt(ps);                          // then mark the end of the utterance
            ad_stop_rec(ad);                         // stop recording
            hyp = ps_get_hyp(ps, NULL);             // query pocketsphinx for "hypothesis" of decoded statement
            return (hyp);                              // the function returns the hypothesis
            break ;
        }
    }
}
