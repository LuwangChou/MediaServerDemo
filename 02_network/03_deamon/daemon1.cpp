#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


//ps -ef | grep testdaemon // see daemon status
//kill -9 (pid) 5479  // kill daemon 
void daemonize(){
	pid_t pid;
	int fd0;
	if( (pid == fork()) < 0 ){
		std::cout << "cant create suprocess! \n" << std::endl;
	}else if(pid != 0 ){ // parent
		exit(0);
		
	}
	
	setsid();//comment 3
	
	if(chdir("/") < 0) { // comment 5
		std::cout << "cant change directory to / \n" << std::endl;
		exit(-1);
	}
	
	fd0 = open("/dev/null",O_RDWR); //comment 7
	
	dup2(fd0,STDIN_FILENO);
	dup2(fd0,STDOUT_FILENO);
	dup2(fd0,STDERR_FILENO);
	
	
}

int main(int argc, char* argv[]){
		daemonize();
		
		while(1){
			sleep(1);
		}

}
