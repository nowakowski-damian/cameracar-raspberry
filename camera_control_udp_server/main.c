/*
 ============================================================================
 Name        : main.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Main function that configures and starts up udp server
 ============================================================================
 */

#include "UdpServer.h"
#include "Logger.h"

int main(int argc, char *argv[]) {
	 save_log("SERVER STARTED");
	 initServos();
     while(1) {
    	 char* error_mssg = runServer();
    	 save_log(error_mssg);
    	 // wait 1 sec and try again
    	 sleep(1);
    	 perror(error_mssg);
     }
	 save_log("SERVER STOPPED");
     return 0;
}
