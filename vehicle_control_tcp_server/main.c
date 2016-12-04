/*
 ============================================================================
 Name        : main.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Main function that starts up tcp server
 ============================================================================
 */


#include "TcpServer.h"
#include "MovementFunctions.h"
#include "Logger.h"

int main(int argc, char *argv[]) {
	initWiringPi();
	save_log("SERVER STARTED");
	while (1) {
		char* error_mssg = runServer();
		// connection aborted - stop motors, center camera
		reset();
		save_log(error_mssg);
		// wait 1 sec and try connect again
		sleep(1);
		perror(error_mssg);
	}
	save_log("SERVER STOPPED");
	return 0;
}
