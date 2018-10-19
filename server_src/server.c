#include "server.h"



t_sphinx    init_sphinx(void)
{
    t_sphinx    ret;

    ret.config = cmd_ln_init(NULL, ps_args(), TRUE,
             "-hmm", "./lang_models/en-us-adapt",
             "-lm", "./lang_models/3538.lm.bin",
             "-dict",  "./lang_models/3538.dict",
             NULL);
    err_set_logfile("sphinx_log");
    ret.ps = ps_init(ret.config);
    // ret.ad = ad_open_dev("sysdefault", (int32) cmd_ln_float32_r(ret.config, "-samprate"));
    return (ret);
}


const char * recognize_from_microphone(ps_decoder_t *ps, int16 bufer[2049])
{
    // int16 adbuf[4096];                               // buffer array to hold audio data
    // uint8 cur_vad_state;                               // flags for tracking active speech - has speech started?
    // uint8 vad_state;                                 //- is speech currently happening?
    int32 k = bufer[2048];                                         // holds the number of frames in the audio buffer
    char const *hyp;                                 // pointer to "hypothesis" (best guess at the decoded result)

    // if (ad_start_rec(ad) < 0)                        // start recording
    // //     E_FATAL("FAILED TO START RECORDING\n");
    if (ps_start_utt(ps) < 0)                                // mark the start of the utterance
        E_FATAL("FAILED TO START UTTERANCE\n");
    printf("HERE\n");
    // printf("%d\n", k);
    // cur_vad_state = 0;                             // clear the utt_started flag
    //printf("READY.....\n");

    // while (1)
    // {
                                      
        // if ((k = ad_read(ad, adbuf, 4096)) < 0)      // capture the number of frames in the audio buffer
        // {
        //     printf("ERROR READ K\n");
        //     return (NULL);
        // }
//        sleep(1);
    if (k != 0)
        ps_process_raw(ps, bufer, 5, FALSE, FALSE);  // send the audio buffer to the pocketsphinx decoder
        printf("HERE2\n");
        // vad_state = ps_get_in_speech(ps);            // test to see if speech is being detected
        // if (vad_state && !cur_vad_state)               // if speech has started and utt_started flag is false
        // {
        //     printf("LISTENING...\n");
        //     //cur_vad_state = TRUE;
        // }
        // if (!vad_state && cur_vad_state)
        // {                                            // if speech has ended and the utt_started flag is true 
            ps_end_utt(ps);                          // then mark the end of the utterance
            printf("HERE3\n");
            //ad_stop_rec(ad);                         // stop recording
            hyp = ps_get_hyp(ps, &k);             // query pocketsphinx for "hypothesis" of decoded statement
            printf("HERE4\n");
            printf("%d: %s\n", k, hyp);
            printf("HERE5\n");
            return (hyp);                            // the function returns the hypothesis
            // if (ps_start_utt(ps) < 0)
                // E_FATAL("FAILED TO START UTTERANCE\n");
            //return (hyp);
            // printf("READY...\n");
        // }
        // cur_vad_state = vad_state;
    // }
    // ad_close(ad);
}


/****************************************************************/
int main(int argc, char const *argv[])
{
    t_sock      sock;
    int16 buffer[2049];
    int fd;
    char   answer[1024];
    
    sock = init_sock();
    fd = open("logs", O_CREAT | O_RDWR | O_APPEND, S_IREAD | S_IWRITE);  
    while (1)
     {
        listen_client(&sock);
        sock.valread = read(sock.new_socket, buffer, 1024);
        

/**********************************************************************************************/
    t_sphinx sp;

    sp = init_sphinx();
    char const *decoded_speech;

    decoded_speech = recognize_from_microphone(sp.ps, buffer);
/*******************************************************************************************************/

        // execute_command(define_command(buffer), buffer, fd, answer);
        // send(sock.new_socket, answer, strlen(answer), 0);
    }
    close(fd);
    return 0;
}
