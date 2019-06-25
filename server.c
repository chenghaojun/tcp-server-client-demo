#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <strings.h>

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in addr;
    bzero(&addr,sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(9999);
    inet_pton(AF_INET,"0.0.0.0",&addr.sin_addr);

    bind(sockfd,(struct sockaddr*)&addr,sizeof(addr));
    listen(sockfd,5);
    while(1) {
        struct sockaddr_in c_addr;
        int c_len = sizeof(c_addr);
        bzero(&c_addr,c_len);
        int c = accept(sockfd,(struct sockaddr*)&addr,&c_len);
        if(c==-1)perror("");
        char ip[40]={0};
        int port;
        inet_ntop(AF_INET,&addr.sin_addr,ip,40);
        port = ntohs(addr.sin_port);
        printf("from %s:%d\n",ip,port);
        close(c);
    }
}

