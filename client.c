#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>



int main(int argc, char* argv[]){
    if(argc == 3){
        //Taking command line arguments
        char message[20];
        strncpy(message, argv[1], sizeof(message) - 1);
        int port = atoi(argv[2]);


        struct sockaddr_in socket_address;
        int client_fd = socket(AF_INET, SOCK_STREAM, 0);
        
 

       	socket_address.sin_family = AF_INET;
       	socket_address.sin_addr.s_addr = htonl(INADDR_ANY);
       	socket_address.sin_port = htons(port);
      	
      	printf("message: %s", message);
       	
       	
       	send(client_fd, message, strlen(message), 0);
       
    	printf("message: %s", message);
    }
}