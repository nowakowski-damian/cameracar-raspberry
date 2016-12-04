/*
 ============================================================================
 Name        : TcpServer.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Main vehicle controller application file including TCP server implementation
 ============================================================================
 */

#include "TcpServer.h"

void onReceive(char* mssg) {

	int err_code = parseMessage(mssg);
	if (err_code != NO_ERROR) {
		save_log(getErrorMessage(err_code));
	}
	printf("Received: [%d %d %d]\n",mssg[0],mssg[1],mssg[2] );
}

void configureAddresStruct(struct sockaddr_in* serverAddr) {
	bzero((char *) serverAddr, sizeof(*serverAddr));
	serverAddr->sin_family = AF_INET;
	serverAddr->sin_port = htons(PORT);
	serverAddr->sin_addr.s_addr = INADDR_ANY;
}

char* runServer() {

	int sockfd;
	int newsockfd;
	socklen_t client_length;
	char buffer[BUFFER_SIZE];
	struct sockaddr_in serv_addr;
	struct sockaddr_in client_addr;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) {
		return "ERROR: opening socket";
	}

	configureAddresStruct(&serv_addr);

	if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
		return "ERROR: on binding";
	}
	listen(sockfd, 1);

	client_length = sizeof(client_addr);

	newsockfd = accept(sockfd, (struct sockaddr *) &client_addr,
			&client_length);
	close(sockfd);
	if (newsockfd < 0) {
		return "ERROR: on accept";
	}

	bzero(buffer, BUFFER_SIZE);
	int size = 0;
	while ((size = read(newsockfd, buffer, BUFFER_SIZE)) > 0) {
		if (size) {
			onReceive(buffer);
		}
		bzero(buffer, BUFFER_SIZE);
	}
	close(newsockfd);
	return "Connection aborted";
}
