/*
 ============================================================================
 Name        : Logger.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Simple file logger
 ============================================================================
 */

#ifndef LOGGER_FILE
#define LOGGER_FILE

#include <stdio.h>
#include <unistd.h>
#include <time.h>

struct tm* getTime();
void save_log(char* log_mssg);

#endif
