#include <iostream>
#include <unistd.h>
#include <signal.h>

void sighandle(int sig)
{
	std::cout<< "signal received: "
	<< sig
	<< std::endl;
}

//SIGPIPE   
int main(int argc, char** argv)
{
	signal(SIGHUP, sighandle);//signal(int sig,void(*func)(int));
	signal(SIGINT, sighandle);
	signal(SIGQUIT, sighandle);
	pause();
	return 0;

}
