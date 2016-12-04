/*
 ============================================================================
 Name        : MovementFunctions.c
 Author      : Damian Nowakowski
 Version     :
 Copyright   : damian.nowakowski@aol.com
 Description : Provides hardware functions for raspberry GPIO controlling
 ============================================================================
 */
#include "MovementFunctions.h"

void initWiringPi() {

	wiringPiSetup();
	piHiPri(99);
	//left motor
	pinMode(MOTOR_LEFT_PWM_PIN, OUTPUT);
	softPwmCreate(MOTOR_LEFT_PWM_PIN, 0, 100);
	pinMode(MOTOR_LEFT_A_PIN, OUTPUT);
	pinMode(MOTOR_LEFT_B_PIN, OUTPUT);
	//right motor
	pinMode(MOTOR_RIGHT_PWM_PIN, OUTPUT);
	softPwmCreate(MOTOR_RIGHT_PWM_PIN, 0, 100);
	pinMode(MOTOR_RIGHT_A_PIN, OUTPUT);
	pinMode(MOTOR_RIGHT_B_PIN, OUTPUT);
	//switches
	pinMode(SWITCH_0_PIN, OUTPUT);
	pinMode(SWITCH_1_PIN, OUTPUT);
	pinMode(SWITCH_2_PIN, OUTPUT);
	pinMode(SWITCH_3_PIN, OUTPUT);
	pinMode(SWITCH_4_PIN, OUTPUT);
	pinMode(SWITCH_5_PIN, OUTPUT);
	pinMode(SWITCH_6_PIN, OUTPUT);
	// reset motors and switches
	reset();
}

int setMotors(signed char right, signed char left) {

	if (right < -100 || right > 100) {
		return VALUE_OVER_RANGE;
	}

	if (left < -100 || left > 100) {
		return VALUE_OVER_RANGE;
	}


	if(right == 0) {
		digitalWrite(MOTOR_LEFT_A_PIN, HIGH);
		digitalWrite(MOTOR_LEFT_B_PIN, HIGH);
	}
	else if (right > 0) {
		softPwmWrite(MOTOR_LEFT_PWM_PIN, (int) right);
		digitalWrite(MOTOR_LEFT_A_PIN, HIGH);
		digitalWrite(MOTOR_LEFT_B_PIN, LOW);
	} else {
		softPwmWrite(MOTOR_LEFT_PWM_PIN, (int) -right);
		digitalWrite(MOTOR_LEFT_A_PIN, LOW);
		digitalWrite(MOTOR_LEFT_B_PIN, HIGH);
	}

        if(left == 0) {
                digitalWrite(MOTOR_RIGHT_A_PIN, HIGH);
                digitalWrite(MOTOR_RIGHT_B_PIN, HIGH);
        }
	else if (left > 0) {
		softPwmWrite(MOTOR_RIGHT_PWM_PIN, (int) left);
		digitalWrite(MOTOR_RIGHT_A_PIN, HIGH);
		digitalWrite(MOTOR_RIGHT_B_PIN, LOW);
	} else {
		softPwmWrite(MOTOR_RIGHT_PWM_PIN, (int) -left);
		digitalWrite(MOTOR_RIGHT_A_PIN, LOW);
		digitalWrite(MOTOR_RIGHT_B_PIN, HIGH);
	}

	return NO_ERROR;
}

int setSwitch(signed char num, signed char boolean) {

	int pinNumber;

	switch (num) {
	case 0:
		pinNumber = SWITCH_0_PIN;
		break;
	case 1:
		pinNumber = SWITCH_1_PIN;
		break;
	case 2:
		pinNumber = SWITCH_2_PIN;
		break;
	case 3:
		pinNumber = SWITCH_3_PIN;
		break;
	case 4:
		pinNumber = SWITCH_4_PIN;
		break;
	case 5:
		pinNumber = SWITCH_5_PIN;
		break;
	case 6:
		pinNumber = SWITCH_6_PIN;
		break;
	default:
		pinNumber = -1;
	}

	if (pinNumber != -1) {
		digitalWrite(pinNumber, boolean == 0 ? LOW : HIGH);
		return NO_ERROR;
	}

	return NO_SUCH_SWITCH;
}

void reset() {
	setMotors(0,0);
	int i;
	for(i=0;i<NUM_OF_SWITCHES;i++) {
		setSwitch(i,0);
	}
}


