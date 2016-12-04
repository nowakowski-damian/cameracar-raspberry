/*
 ============================================================================
 Name        : Error.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Error handler file with error codes and describe function
 ============================================================================
 */
#include "Error.h"

char* getErrorMessage(int err_code) {
	switch (err_code) {
	case NO_SUCH_SWITCH:
		return "ERROR: MovementFunctions.c/setSwitch()/no such switch";
	case PARSING_ERROR_WRONG_TYPE:
		return "ERROR: ApiParser.c/parseMessage()/wrong type id";
	case VALUE_OVER_RANGE:
		return "ERROR: MovementFunctions.c/setMotors()/motor value over range";
	default:
		return "ERROR: Unknown error";
	}
}
