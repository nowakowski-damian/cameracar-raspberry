/*
 ============================================================================
 Name        : Error.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Error handler file with error codes and describe function
 ============================================================================
 */

#ifndef ERROR_HANDLER_FILE
#define ERROR_HANDLER_FILE

#define NO_ERROR 0
#define UNKNOWN_ERROR -1

#define NO_SUCH_SWITCH -2
#define PARSING_ERROR_WRONG_TYPE -3
#define VALUE_OVER_RANGE -4

char* getErrorMessage(int err_code);

#endif
