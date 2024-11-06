#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>



int main(int argc, char* argv[])
{
	if(argc == 2){
	char message[1024];
	int port = atoi(argv[1]);
	
	int server_fd = socket(AF_INET, SOCK_STREAM, 0);
	
	struct sockaddr_in socket_address;
	
	socket_address.sin_family = AF_INET;
	socket_address.sin_addr.s_addr = htonl(INADDR_ANY);
	socket_address.sin_port = htons(port);
	
	int returnVal;
	
	returnVal = bind(
	server_fd, (struct sockaddr*)&socket_address, sizeof(socket_address));
	
	printf("Server listining");
	returnVal = listen(server_fd, 5);
	
	
	struct sockaddr_in client_address;
	socklen_t client_address_len = sizeof(client_address);
	
	int client_fd = accept(
	server_fd, (struct sockaddr*)&client_address, &client_address_len);
	
	ssize_t valRead = read(client_fd, message, sizeof(message)-1);
	printf("%s\n", message);
	
	
	close(client_fd);
	close(server_fd);
	
}
	
	return 0;
}
