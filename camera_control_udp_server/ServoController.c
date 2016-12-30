/*
 ============================================================================
 Name        : ServoController.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Servo conroller source file
 ============================================================================
 */

#include "ServoController.h"

double xDegreeToLevel;
double yDegreeToLevel;

int lastXlevel=0;
int lastYlevel=0;

void initServos(){
	wiringPiSetup();
	piHiPri(50);
	pinMode(SERVO_X_PIN,PWM_OUTPUT);
	pinMode(SERVO_Y_PIN,PWM_OUTPUT);
	pwmSetMode(PWM_MODE_MS);
	pwmSetClock(CLOCK_DIVIDER);
	pwmSetRange(PWM_RANGE);
	// center
	pwmWrite(SERVO_X_PIN,SERVO_X_CENTER);
	pwmWrite(SERVO_Y_PIN,SERVO_Y_CENTER);
	// count servos levels
	int xServoLevels;
	int yServoLevels;
	xServoLevels = SERVO_X_STOP - SERVO_X_CENTER;
	xDegreeToLevel=1.*xServoLevels/SERVO_MAX_DEGREE;
	yServoLevels = SERVO_Y_STOP - SERVO_Y_CENTER;
	yDegreeToLevel=1.*yServoLevels/SERVO_MAX_DEGREE;
}

void setX(int xDegrees){
	// convert degrees to servo levels
	int levelsFromCenter =(int) xDegrees*xDegreeToLevel;
	int level;
	if(xDegrees<0){
		level = max(SERVO_X_CENTER+levelsFromCenter,SERVO_X_START);
	}
	else{
		level = min(SERVO_X_CENTER+levelsFromCenter,SERVO_X_STOP);
	}

	printf("XLEVEL: %d",level);
	pwmWrite(SERVO_X_PIN,level);
}

void setY(int yDegrees){
	// convert degrees to servo levels
	int levelsFromCenter =(int) yDegrees*yDegreeToLevel;
	int level;
	if(yDegrees<0){
		level = max(SERVO_Y_CENTER+levelsFromCenter,SERVO_Y_START);
	}
	else{
		level = min(SERVO_Y_CENTER+levelsFromCenter,SERVO_Y_STOP);
	}
	pwmWrite(SERVO_Y_PIN,level);
}

void setServos(int xDegrees,int yDegrees){
	setX(xDegrees);
	setY(yDegrees);
}

int min(int a,int b){
	return a>b ? b : a ;
}

int max(int a,int b){
	return a<b ? b : a ;
}
