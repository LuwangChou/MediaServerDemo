#include <iostream>
#include "server.h"

int main(int argc, char* argv[]){
	
	avdance::Server* server = new avdance::Server();
	if(server){
		server->run();	
	}
	return 0;
}
