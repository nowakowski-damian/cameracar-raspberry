/*
 ============================================================================
 Name        : UdpServer.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : UDP server implementation
 ============================================================================
 */

#ifndef UDP_SERVER_FILE
#define UDP_SERVER_FILE

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include "ServoController.h"

#define PORT 8001
#define BUFFER_SIZE 2

void onReceive(signed char* mssg);
void configureAddresStruct(struct sockaddr_in* serverAddr);
char* runServer();

#endif
