#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#define PORT 9876
#define MESSAGE_SIZE 1024
int main(int argc,char* argv[]){
	int socket_fd,accept_fd;
	int on = 1;
	int n = 0;
	int curpos = 0;
	int backlog = 10;
	char in_buf[MESSAGE_SIZE] = {0};
	char out_buf[MESSAGE_SIZE] = "hello welcome to server world";
	
	socket_fd = socket(AF_INET,SOCK_DGRAM,0);
	if(socket_fd < 0){
		std::cout<< "Failed to create socket !" << std::endl;
		exit(-1);
	}
	
	/*
	struct sockaddr 
	{
		sa_family_t sin_family;
		char sin_zero[14];
	}
	*/
	struct sockaddr_in localaddr, remote_addr;
	int ret = setsockopt(socket_fd,
				SOL_SOCKET,
				SO_REUSEADDR,
				&on,
				(socklen_t)sizeof(on) );
							
	if(ret == -1){
		std::cout << "Failed to set sockedt options!" << std::endl;
	}
	
	localaddr.sin_family = AF_INET;
	localaddr.sin_port = PORT;
	localaddr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(localaddr.sin_zero), 8);
   //int bind(int sockfd, const struct sockaddr *addr,
   //             socklen_t addrlen);

	int bind_ret = bind(socket_fd, (const struct sockaddr *) &localaddr,sizeof(struct sockaddr));
	
	if(bind_ret == -1){
		std::cout << "Failed to bind addr" << std::endl;
		exit(-1);
	}
	
	
	socklen_t addr_len =  sizeof(struct sockaddr_in);
	//loop
	std::cout << "start loop";
	for(;;){
	
		n = recvfrom(socket_fd, in_buf, MESSAGE_SIZE-1,0,(struct sockaddr*) &remote_addr, &addr_len);
		
		if(n > 0){
			in_buf[n] = 0;
						
			std::cout << "receive data from client :" << inet_ntoa(remote_addr.sin_addr) << ntohs(remote_addr.sin_port) <<in_buf ;
			n = sendto(socket_fd, out_buf, strlen(out_buf),0,(struct sockaddr*) &remote_addr, sizeof(remote_addr));
			if(n < 0){
				std::cout << "sendto error" << std::endl;
				break;
			}
				
		}else if(n==0){
				std::cout << "client closed" <<std::endl;
		}else{
			std::cout << "recv error" << n <<std::endl;
		}
	}
	return 0;


	

}
