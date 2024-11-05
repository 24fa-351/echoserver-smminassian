#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char* argv[]){
    if(argc == 2){
        char message[20] = argv[1];
        int -p = atoi(argv[2]);
        struct sockaddr_in serv_addr;
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

        
    }
}