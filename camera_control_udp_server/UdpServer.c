/*
 ============================================================================
 Name        : UdpServer.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : UDP server implementation
 ============================================================================
 */

#include "UdpServer.h"

void onReceive(signed char* mssg) {
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