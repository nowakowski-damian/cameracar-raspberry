/*
 ============================================================================
 Name        : main.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Main function that configures and starts up udp server
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include "ServoController.h"

const int PORT = 8001;
const int BUFFER_SIZE = 2;

void onReceive(signed char* mssg){
	int x = (int) mssg[0];
	int y = (int) mssg[1];
	printf("Received: [ %d,%d ]\n",x,y);
	setServos(x,y);
}

void configureAddresStruct(struct sockaddr_in* serverAddr){
  bzero((char *) serverAddr, sizeof(*serverAddr));
  serverAddr->sin_family = AF_INET;
  serverAddr->sin_port = htons(PORT);
  serverAddr->sin_addr.s_addr = INADDR_ANY;
}

char* runServer() {
  int sockfd;
  signed char buffer[BUFFER_SIZE];
  struct sockaddr_in serverAddr;
  /*Create UDP socket*/
  sockfd = socket(PF_INET, SOCK_DGRAM, 0);
  if (sockfd < 0) {
 	 return "ERROR opening socket";
  }
  configureAddresStruct(&serverAddr);
  if( bind(sockfd, (struct sockaddr *) &serverAddr, sizeof(serverAddr)) < 0 ){
	 return "ERROR on binding";
  }
  int size=0;
  while( (size=recv(sockfd,buffer,BUFFER_SIZE,0)) > 0 ) {
	  if(size){
		  onReceive(buffer);
	  }
     bzero(buffer,BUFFER_SIZE);
  }

  return "Connection aborted";
}

struct tm* getTime() {
	time_t ltime = time(NULL);
	return localtime(&ltime);
}

void save_log(char* log_mssg){
	FILE *logs = fopen("udp_server.log","a");
	struct tm* time = getTime();
	fprintf(logs,"%02d.%02d.%d %02d:%02d:%02d %s\n",
			time->tm_mday,time->tm_mon,time->tm_year+1900,
			time->tm_hour, time->tm_min, time->tm_sec,log_mssg);
	 fclose(logs);
}


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
