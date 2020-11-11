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
#define SERVER_PORT 9876
#define MESSAGE_SIZE 1024
int main(int argc,char* argv[]){
	
	
	int ret = -1;
	int socket_fd;
	
	//server addr
	struct sockaddr_in serverAddr;
	
	char sendbuf[MESSAGE_SIZE] = "Hello client";
	char recvbuf[MESSAGE_SIZE] = {0};
	int n = 0;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = SERVER_PORT;
	serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	
	
	std::cout << "this is a UDP client... \n";
	
	int data_len;
	socket_fd = socket(AF_INET, SOCK_DGRAM,0);
	if( socket_fd  < 0){
		std::cout << "socket error";
		exit(-1);
	}

	std::cout << "start client socket successfully.... \n";
	if(serverAddr.sin_addr.s_addr == INADDR_NONE){
		std::cout << "Incorrect ip address " << std::endl;
		close(socket_fd);
		exit(-1);
	}
		
	n = sendto(socket_fd, sendbuf, strlen(sendbuf),0,(struct sockaddr*) &serverAddr, sizeof(serverAddr));
	if(n < 0){
		std::cout << "sendto error " << std::endl;
		close(socket_fd);
		
	}
	std::cout << "sendto successfully.... \n";
	socklen_t len = sizeof(serverAddr);
	n = recvfrom(socket_fd, recvbuf, MESSAGE_SIZE-1,0,(struct sockaddr*) &serverAddr,&len);
	if(n > 0){
		recvbuf[n] = 0;
		std::cout << "received from server" << std::endl;
		std::cout << recvbuf;
		//puts(recvbuf);
	}
	else if( n==0){
		std::cout << "server closed." << std::endl;
	}
	else if(n == -1){
		std::cout << "recvfrom error" << std::endl;
	}
	
	close(socket_fd);
	std::cout << "close socket successfully.... \n";


	return 0;
}
