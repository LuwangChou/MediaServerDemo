#include <iostream>
#include <unistd.h>
#include <signal.h>
void sighandler(int sig)
{
	std::cout << "received signal: "
	<< sig
	<< std::endl;

}

/*

struct sigaction{
	void (*sa_handler)(int);// handle function
	void (*sa_sigaction)(int, siginfo_t*, void*);// handle function
	sigset_tsa_mask; // mask code
	int sa_flags; //  SA_SIGINFO  mark selection
	sa_handler/sa_sigaction
	void (*sa_restorer)(void);// setting to NULL, not commonly used
}

*/

int main(int argc, char* argv[])
{
	struct sigaction act, oact;
	
	act.sa_handler = sighandler;
	sigfillset(&act.sa_mask);
	act.sa_flags = 0;
	
	sigaction(SIGINT, &act, &oact);
	pause();
	return 0;

}
