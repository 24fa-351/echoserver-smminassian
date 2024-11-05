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
        //Taking command line arguments
        char message[20];
        strncopy(message, argv[1], sizeof(message) - 1)
        int port = atoi(argv[2]);


        struct sockaddr_in serv_addr;
        int socket_fd = socket(AF_INET, SOCK_STREAM, 0);

        if(socket_fd < 0){
            perror("Socket creation error");
            return -1;
        }
        
    }
}