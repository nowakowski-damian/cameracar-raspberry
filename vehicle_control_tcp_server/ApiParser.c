/*
 ============================================================================
 Name        : ApiParser.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Parser for receiving packets - decides which function should be invoked
 ============================================================================
 */

#include "ApiParser.h"

int parseMessage(char* data) {

	switch (data[0]) {
	case SET_MOTORS_ID:
		return setMotors(data[1], data[2]);
	case SET_SWITCH_ID:
		return setSwitch(data[1], data[2]);
	default:
		return PARSING_ERROR_WRONG_TYPE;
	}
}
