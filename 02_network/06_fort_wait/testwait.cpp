#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
	pid_t pid = -1;
	for(int i=0;i<4;i++){
		if(pid!=0){
			pid = fork();
		}
	}
	
	if(pid == 0){
		sleep(2);
	}else{
		while((pid==waitpid(-1,NULL,0)) != -1){
			std::cout << "the pid is dead. pid == "<< pid<< std::endl; 
		}
	}
	return 0;
}
