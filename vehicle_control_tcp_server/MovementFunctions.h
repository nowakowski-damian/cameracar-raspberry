/*
 ============================================================================
 Name        : MovementFunctions.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Provides hardware functions for raspberry GPIO controlling
 ============================================================================
 */

#ifndef MOVEMENT_FUNCTIONS_FILE
#define MOVEMENT_FUNCTIONS_FILE

#include <wiringPi.h>
#include <softPwm.h>
#include "Error.h"

void initWiringPi(void);
int setMotors(signed char, signed char);
int setSwitch(signed char,signed char);
void reset(void)
;
// pin numbers in wiringPi numbering format
#define MOTOR_LEFT_PWM_PIN 8
#define MOTOR_LEFT_A_PIN 9
#define MOTOR_LEFT_B_PIN 7

#define MOTOR_RIGHT_PWM_PIN 15
#define MOTOR_RIGHT_A_PIN 16
#define MOTOR_RIGHT_B_PIN 1

#define NUM_OF_SWITCHES 7
#define SWITCH_0_PIN 2
#define SWITCH_1_PIN 3
#define SWITCH_2_PIN 12
#define SWITCH_3_PIN 13
#define SWITCH_4_PIN 14
#define SWITCH_5_PIN 30
#define SWITCH_6_PIN 21

#endif
