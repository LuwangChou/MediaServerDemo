#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <arpa/inet.h>
#define SERVER_PORT 8111
#define MESSAGE_SIZE 1024
int main(int argc,char* argv[]){
	
	
	int ret = -1;
	int socket_fd;
	
	//server addr
	struct sockaddr_in serverAddr;
	
	char sendbuf[MESSAGE_SIZE];
	char recvbuf[MESSAGE_SIZE];
	
	
	int data_len;
	socket_fd = socket(AF_INET, SOCK_STREAM,0);
	if( socket_fd  < 0){
		std::cout << "socket error";
		exit(-1);
	}
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = SERVER_PORT;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	ret = connect(socket_fd, (struct sockaddr* ) & serverAddr, sizeof(struct sockaddr));
	if(ret < 0 ){
		std::cout << "connect error";
		exit(-1);
	}
	
	
	std::cout << "success to connect server... \n";
	
	while(1){
		memset(sendbuf, 0, MESSAGE_SIZE);
		
		std::cout << "Sending message" << std::endl;
		gets(sendbuf);
		
		
		ret = send(socket_fd, sendbuf, strlen(sendbuf), 0);
		if(ret <= 0){
			std::cout << "the connection is disconnected!\n";
			break;
		}
		
		
		if(strcmp(sendbuf, "quit")== 0){
			break;
		}
		
		std::cout << "echo  message";
		
		recvbuf[0] = '\0';
		data_len = recv(socket_fd, recvbuf, MESSAGE_SIZE,0);
		recvbuf[data_len] = '\0';
		
		std::cout << "recvbuf==" << recvbuf << std::endl;
	
	}
	
	close(socket_fd);
	


	return 0;
}
