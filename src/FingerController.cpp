/*
 * FingerController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "FingerController.h"
#include <stdio.h>
#include "DIO.h"
#include "AIO.h"
#include "RotaryEncoder.h"
#include "LimitSwitch.h"
#include <unistd.h>

FingerController::FingerController(){
	printf("Projectgroep C2 - Finger controller");
	printf("\n");

	motor_controller1 = new MotorController(&MOTOR1_CONFIG, &MOTOR1_ENCODER_CONFIG,
			&MOTOR1_END_SWITCH1_CONFIG, &MOTOR1_END_SWITCH2_CONFIG);
//
	motor_controller2 = new MotorController(&MOTOR2_CONFIG, &MOTOR2_ENCODER_CONFIG,
				&MOTOR1_END_SWITCH1_CONFIG, &MOTOR1_END_SWITCH2_CONFIG);
//
	motor_controller3 = new MotorController(&MOTOR3_CONFIG, &MOTOR3_ENCODER_CONFIG,
					&MOTOR1_END_SWITCH1_CONFIG, &MOTOR1_END_SWITCH2_CONFIG);

	printf("Setup done \n");
}

FingerController::~FingerController(){
	delete motor_controller1;
	delete motor_controller2;
	delete motor_controller3;
}

void FingerController::run(){
	printf("Start running\n");
	printf("Start kalibratie\n");

	motor_controller1->calibrate();
//	motor_controller1->setMotorPosition(0.0);

	motor_controller1->setState(running);

	for(;;){
//		printf("Switch1: %d, switch2: %d\n", motor_controller1->end_switch_1->hasReachedLimit(), motor_controller1->end_switch_2->hasReachedLimit());
		motor_controller1->run();

		usleep(1000000 / TICKS_PER_SECOND);
	}
}
