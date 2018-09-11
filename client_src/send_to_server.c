#include "client.h"

int send_command(char const *decoded_speech)
{
    struct sockaddr_in address;
    int sock = 0, valread;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
  
    memset(&serv_addr, '0', sizeof(serv_addr));
  
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
      
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
    }
    return 0;
}
