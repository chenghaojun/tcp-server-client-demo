#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int sockfd = socket(AF_INET,SOCK_STREAM, 0);
    if(sockfd==-1) perror("sock");
    struct sockaddr_in mine, dest;
    
    bzero(&mine, sizeof(mine));
    mine.sin_family = AF_INET;
    mine.sin_port = htons(3334);
    inet_pton(AF_INET, "192.168.77.129", &mine.sin_addr);
    
    bzero(&dest, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(9999);
    inet_pton(AF_INET, "192.168.77.129", &dest.sin_addr);

    int b = bind(sockfd, (struct sockaddr*)&mine, sizeof(mine));
    if(b==-1) perror("");
    
    int c = connect(sockfd, (struct sockaddr*)&dest, sizeof(dest));
    if(c!=0) perror("");
    close(sockfd);
}

