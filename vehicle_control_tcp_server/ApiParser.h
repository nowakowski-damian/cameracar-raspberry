/*
 ============================================================================
 Name        : ApiParser.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Parser for receiving packets - decides which function should be invoked
 ============================================================================
 */

#ifndef API_PARSER_FILE
#define API_PARSER_FILE

#include "MovementFunctions.h"
#include "Error.h"

int parseMessage(char*);

#define SET_MOTORS_ID 1
#define SET_SWITCH_ID 2

#endif
