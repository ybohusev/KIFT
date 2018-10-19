#include "client.h"

void recognize_from_microphone(ad_rec_t *ad, int16 buf[2049])
{
    // int16 adbuf[4096];                               // buffer array to hold audio data
    // uint8 cur_vad_state;                               // flags for tracking active speech - has speech started?
    // uint8 vad_state;                                 //- is speech currently happening?
    int32 buflen;                                         // holds the number of frames in the audio buffer
    int32 bufread;
    // // char const *hyp;                                 // pointer to "hypothesis" (best guess at the decoded result)

    if (ad_start_rec(ad) < 0)                        // start recording
        E_FATAL("FAILED TO START RECORDING\n");
    // // if (ps_start_utt(ps) < 0)                                // mark the start of the utterance
    // //     E_FATAL("FAILED TO START UTTERANCE\n");
    // cur_vad_state = 0;                             // clear the utt_started flag
    buflen = 0;
    // while (buflen < 2048)
    // {
        bufread = 0;                       
        if ((bufread = ad_read(ad, buf, 2048)) < 0)      // capture the number of frames in the audio buffer
        {
            printf("ERROR READ K\n");
            return ;
        // }
        // buflen += bufread;
    }
    buf[2048] = bufread;
        // printf("->>> %d\n", k);
        // else
        //     return (buf);
    //     ps_process_raw(ps, adbuf, k, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder
        // vad_state = ps_get_in_speech(ps);            // test to see if speech is being detected
        // if (vad_state && !cur_vad_state)              // if speech has started and utt_started flag is false
        //     {
        //         cur_vad_state = 1;
        //         printf("LISTENING...\n");
        //     }
        // if (!vad_state && cur_vad_state)
        // {                                            // if speech has ended and the utt_started flag is true 
        //     // ps_end_utt(ps);                          // then mark the end of the utterance
            ad_stop_rec(ad);                         // stop recording
    //         hyp = ps_get_hyp(ps, &k);             // query pocketsphinx for "hypothesis" of decoded statement
            // ad_close(ad);
            // return ;                            // the function returns the hypothesis
    //         // if (ps_start_utt(ps) < 0)
    //         //     E_FATAL("FAILED TO START UTTERANCE\n");
    //         // printf("READY...\n");
        // }
    //     cur_vad_state = vad_state;
    // }
    // ad_close(ad);
}
