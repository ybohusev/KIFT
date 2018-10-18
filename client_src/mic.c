#include "client.h"

const char * recognize_from_microphone(ps_decoder_t *ps, ad_rec_t *ad)
{
    int16 adbuf[4096];                               // buffer array to hold audio data
    uint8 cur_vad_state;                               // flags for tracking active speech - has speech started?
    uint8 vad_state;                                 //- is speech currently happening?
    int32 k;                                         // holds the number of frames in the audio buffer
    char const *hyp;                                 // pointer to "hypothesis" (best guess at the decoded result)

    if (ad_start_rec(ad) < 0)                        // start recording
        E_FATAL("FAILED TO START RECORDING\n");
    if (ps_start_utt(ps) < 0)                                // mark the start of the utterance
        E_FATAL("FAILED TO START UTTERANCE\n");
    cur_vad_state = 0;                             // clear the utt_started flag
    //printf("READY.....\n");

    while (1)
    {
                                      
        if ((k = ad_read(ad, adbuf, 4096)) < 0)      // capture the number of frames in the audio buffer
        {
            printf("ERROR READ K\n");
            return (NULL);
        }
//        sleep(1);
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder
        vad_state = ps_get_in_speech(ps);            // test to see if speech is being detected
        if (vad_state && !cur_vad_state)               // if speech has started and utt_started flag is false
        {
            printf("LISTENING...\n");
            //cur_vad_state = TRUE;
        }
        if (!vad_state && cur_vad_state)
        {                                            // if speech has ended and the utt_started flag is true 
            ps_end_utt(ps);                          // then mark the end of the utterance
            //ad_stop_rec(ad);                         // stop recording
            hyp = ps_get_hyp(ps, &k);             // query pocketsphinx for "hypothesis" of decoded statement
            printf("%d: %s\n", k, hyp);
            //return (hyp);                            // the function returns the hypothesis
            if (ps_start_utt(ps) < 0)
                E_FATAL("FAILED TO START UTTERANCE\n");
            //return (hyp);
            printf("READY...\n");
        }
        cur_vad_state = vad_state;
    }
    ad_close(ad);
}
