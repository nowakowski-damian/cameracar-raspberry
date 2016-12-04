/*
 ============================================================================
 Name        : Logger.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Simple file logger
 ============================================================================
 */

#include "Logger.h"

struct tm* getTime() {
	time_t ltime = time(NULL);
	return localtime(&ltime);
}

void save_log(char* log_mssg) {
	printf("%s\n", log_mssg);
	FILE *logs = fopen("tcp_server.log", "a");
	struct tm* time = getTime();
	fprintf(logs, "%02d.%02d.%d %02d:%02d:%02d %s\n", time->tm_mday,
			time->tm_mon, time->tm_year + 1900, time->tm_hour, time->tm_min,
			time->tm_sec, log_mssg);
	fclose(logs);
}
