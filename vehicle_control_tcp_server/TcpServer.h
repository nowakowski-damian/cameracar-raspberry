/*
 ============================================================================
 Name        : TcpServer.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Main vehicle controller application file including TCP server implementation
 ============================================================================
 */

#ifndef TCP_SERVER_FILE
#define TCP_SERVER_FILE

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <strings.h>
#include "ApiParser.h"
#include "Error.h"
#include "Logger.h"

#define PORT 8000
#define BUFFER_SIZE 3

void onReceive(char* mssg);
void configureAddresStruct(struct sockaddr_in* serverAddr);
char* runServer();

#endif
