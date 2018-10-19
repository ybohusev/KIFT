#include "client.h"

const char * recognize_from_microphone(ps_decoder_t *ps, ad_rec_t *ad)
{
    int16 adbuf[4096];
    uint8 cur_vad_state;
    uint8 vad_state;
    int32 k;
    char const *hyp;

    if (ad_start_rec(ad) < 0)
        E_FATAL("FAILED TO START RECORDING\n");
    if (ps_start_utt(ps) < 0)
        E_FATAL("FAILED TO START UTTERANCE\n");
    cur_vad_state = 0;

    while (1)
    {
                                      
        if ((k = ad_read(ad, adbuf, 4096)) < 0)
        {
            printf("ERROR READ K\n");
            return (NULL);
        }
        ps_process_raw(ps, adbuf, k, FALSE, FALSE);
        vad_state = ps_get_in_speech(ps);
        if (vad_state && !cur_vad_state)
        {
            printf("LISTENING...\n");
        }
        if (!vad_state && cur_vad_state)
        {
            ps_end_utt(ps);
            hyp = ps_get_hyp(ps, &k);
            printf("%d: %s\n", k, hyp);
            return (hyp);
            if (ps_start_utt(ps) < 0)
                E_FATAL("FAILED TO START UTTERANCE\n");
            printf("READY...\n");
        }
        cur_vad_state = vad_state;
    }
    ad_close(ad);
}
