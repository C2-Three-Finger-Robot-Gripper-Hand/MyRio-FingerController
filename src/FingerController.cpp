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
#include "ModbusCommunicator.h"

FingerController::FingerController(){
	printf("Projectgroep C2 - Finger controller");
	printf("\n");


	motor_controller1 = new MotorController(&MOTOR1_CONFIG, &MOTOR1_ENCODER_CONFIG,
			&MOTOR3_END_SWITCH1_CONFIG, &MOTOR3_END_SWITCH2_CONFIG);

	motor_controller2 = new MotorController(&MOTOR2_CONFIG, &MOTOR2_ENCODER_CONFIG,
				&MOTOR3_END_SWITCH1_CONFIG, &MOTOR3_END_SWITCH2_CONFIG);

	motor_controller3 = new MotorController(&MOTOR3_CONFIG, &MOTOR3_ENCODER_CONFIG,
					&MOTOR3_END_SWITCH1_CONFIG, &MOTOR3_END_SWITCH2_CONFIG);


	ModbusCommunicator::start_thread(this);
	printf("Setup done \n");
}

FingerController::~FingerController(){
	delete motor_controller1;
	delete motor_controller2;
	delete motor_controller3;
}

void FingerController::run(){
  printf("Start kalibratie\n");
	motor_controller3->calibrate();
	printf("eind kalibratie, max steps: %d\n", motor_controller3->max_steps);

	for(;;){
		if (motor_controller3->end_switch_2->hasReachedLimit()) {
			motor_controller3->motor->forwards();
		}
		if (motor_controller3->end_switch_1->hasReachedLimit()) {
			motor_controller3->motor->backwards();
		}
	  usleep(1000000 / TICKS_PER_SECOND);
  }
 }
