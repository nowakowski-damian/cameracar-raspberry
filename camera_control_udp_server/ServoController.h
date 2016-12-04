/*
 ============================================================================
 Name        : ServoController.h
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Servo conroller header file
 ============================================================================
 */

#ifndef SERVOCONTROLLER_H_
#define SERVOCONTROLLER_H_

#include <wiringPi.h>
#include <unistd.h>

// PIN SETTINGS ( pin numbers in wiringPi numbering format )
#define SERVO_X_PIN 26
#define SERVO_Y_PIN 23

//PWM SETTINGS ( pwm's clock derives from 19,2MHz raspberry clock )
//clock at 50kHz (20us tick)
#define CLOCK_DIVIDER 384
 //range at 1000 ticks (20ms)
#define PWM_RANGE 1000

// SERVO SPECIFIC SETTINGS - Hitec HS82MG
// max angle in degrees for each servo
#define SERVO_MAX_DEGREE 88
// range for servo X (0-1000)
#define SERVO_X_START 39
#define SERVO_X_CENTER 81
#define SERVO_X_STOP 123
// range for servo Y (0-1000)
#define SERVO_Y_START 33
#define SERVO_Y_CENTER 75
#define SERVO_Y_STOP 117

// ADDITIONAL CONSTANTS
#define SOFT_SLEEP_TIME_US 1000

void initServos();
void setX(int xDegrees);
void setY(int yDegrees);
void setServos(int xDegrees,int yDegrees);
int min(int,int);
int max(int,int);
void pwmWriteSoftly(int SERVO_PIN,int level);
#endif /* SERVOCONTROLLER_H_ */
