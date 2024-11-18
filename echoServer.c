#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define LISTEN_BACKLOG 5
#define Port 8080

//input pointer is freed by this function
void handleConnection(int* sock_fd_ptr){
	int sock_fd = *sock_fd_ptr; 
	free(sock_fd_ptr);
	printf("Handling Connection on %d\n", sock_fd);
	 char buffer[1024];
	 int bytes_read = read(sock_fd, buffer, sizeof(buffer));
	 printf("Received: %s\n", buffer);
	 write(sock_fd, buffer, bytes_read);
	 printf("Done with connection on %d\n", sock_fd);
}

int main(int argc, char* argv[]){
 	
	int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
        struct sockaddr_in socket_address;
 
 	memset(&socket_address, '\0', sizeof(socket_address));
       	socket_address.sin_family = AF_INET;
       	socket_address.sin_addr.s_addr = htonl(INADDR_ANY);
       	socket_address.sin_port = htons(Port);
       	
       	int returnVal;
       	
       	returnVal = bind(
       		socket_fd, (struct sockaddr*)&socket_address, sizeof(socket_address));
       		
       	returnVal = listen(socket_fd, LISTEN_BACKLOG);
       	
       	struct sockaddr_in client_address;
       	socklen_t client_address_len = sizeof(client_address);
		
       	while(1){
       	
       	pthread_t thread;
       	int *client_fd_buf = malloc(sizeof(int));
		
		*client_fd_buf = accept(
       	socket_fd, (struct sockaddr*)&client_address, &client_address_len);

		printf("Accepted on %d\n", *client_fd_buf);

		pthread_create(&thread, NULL, (void* (*)
		(void*))handleConnection, (void*)client_fd_buf);
       	}
       	return 0;
       	
}
       
