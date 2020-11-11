#include <iostream>
#include <unistd.h>
#include <stdlib.h>

#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>

#define PORT 8111
#define MESSAGE_SIZE 1024
int main(int argc,char* argv[]){
	int socket_fd,accept_fd;
	int on = 1;
	int pid = -1;
	int curpos = 0;
	int backlog = 10;
	char in_buf[MESSAGE_SIZE] = {0,};
	
	
	socket_fd = socket(AF_INET,SOCK_STREAM,0);
	if(socket_fd == -1){
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
	
	int listen_ret = listen(socket_fd, backlog);
	
	if(ret == -1){
		std::cout << "listen error" << std::endl;
	}
	
	socklen_t addr_len =  sizeof(struct sockaddr_in);
	//create sub process
	pid = fork();
	//loop
	for(;;){
		//sub process
		if(pid == 0){
			//accept an new connection
			accept_fd = accept(socket_fd, (struct sockaddr *) &remote_addr, &addr_len);
			for(;;){
				memset(in_buf, 0, MESSAGE_SIZE);
			
				//receive network data and print it
			
				int recv_ret = recv(accept_fd, (void*) in_buf, MESSAGE_SIZE, 0);
				if(recv_ret == 0){
					break;
				}
			
				std::cout << "receive message :" << in_buf ;
				send(accept_fd, (void*) in_buf, MESSAGE_SIZE, 0);

			
			}
			std::cout << "close client connection..." ;
			close(accept_fd);
		}
		//parent process
		sleep(1000);
	}
	
	if(pid != 0){
	
		std::cout << "close server ..." ;
		close(socket_fd);
	}
	return 0;


	

}
