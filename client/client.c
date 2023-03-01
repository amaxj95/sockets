#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

//client socket for server communication
short socketCreate(void){
    short hSocket;
    printf("Creating socket\n");
    hSocket = socket(AF_INET, SOCK_STREAM, 0);
    return hSocket;
}

//try to connect
int socketConnect(int hSocket){
    int iRetval=-1;
    int ServerPort = 12345;

    struct sockaddr_in remote = {0};
    remote.sin_addr.s_addr = inet_addr("https://amaxj95-shiny-telegram-7rvx4g4xg7wcwqx7-12345.preview.app.github.dev/"); //127.0.0.1
    remote.sin_family = AF_INET;
    remote.sin_port = htons(ServerPort);

    iRetval = connect(hSocket,(struct sockaddr *)&remote,sizeof(remote));
    return iRetval;
}

int socketSend(int hSocket,char* Rqst, short lenRqst){
    int shortRetval=-1;
    struct timeval tv;
    tv.tv_sec = 20;
    tv.tv_usec = 0;

    if(setsockopt(hSocket,SOL_SOCKET,SO_SNDTIMEO,(char *)&tv,sizof(tv)) < 0) {
        printf("Time Out\n");
        return -1;
    }
}