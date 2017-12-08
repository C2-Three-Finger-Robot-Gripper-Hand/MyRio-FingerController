/*
 * FingerController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include <stdio.h>

#include "FingerController.h"
#include "ModbusCommunicator.h"

FingerController::FingerController(){
	printf("Project C2 - Finger controller \n");


	motor_controller1 = new MotorController(&MOTOR1_CONFIG, &MOTOR1_ENCODER_CONFIG,
			&MOTOR1_END_SWITCH1_CONFIG, &MOTOR1_END_SWITCH2_CONFIG);

	motor_controller2 = new MotorController(&MOTOR2_CONFIG, &MOTOR2_ENCODER_CONFIG,
				&MOTOR1_END_SWITCH1_CONFIG, &MOTOR1_END_SWITCH2_CONFIG);

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
	ModbusCommunicator *modbus_controller = new ModbusCommunicator(this);

	printf("Start calibrating\n");
	motor_controller1->calibrate();
	//motor_controller2->calibrate();
	//motor_controller3->calibrate();

	printf("Start running\n");
	motor_controller1->setState(running);
	//motor_controller2->setState(running);
	//motor_controller3->setState(running);

	for(;;){
		modbus_controller->run();

		motor_controller1->run();
		//motor_controller2->run();
		//motor_controller3->run();
	}
}
