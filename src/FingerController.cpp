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
				&MOTOR2_END_SWITCH1_CONFIG, &MOTOR2_END_SWITCH2_CONFIG);

	motor_controller3 = new MotorController(&MOTOR3_CONFIG, &MOTOR3_ENCODER_CONFIG,
					&MOTOR3_END_SWITCH1_CONFIG, &MOTOR3_END_SWITCH2_CONFIG);

	mode = controller_idle_mode;

	printf("Setup done \n");
}

FingerController::~FingerController(){
	delete motor_controller1;
	delete motor_controller2;
	delete motor_controller3;
}

void FingerController::run(){
	ModbusCommunicator *modbus_controller = new ModbusCommunicator(this);

	mode = controller_idle_mode;

	printf("Start running\n");

	for(;;){
		modbus_controller->run();
		if(mode == controller_running_mode){
			motor_controller1->run();
			//motor_controller2->run();
			//motor_controller3->run();
		}
	}
}

void FingerController::set_controller_mode(double mode_number){
	if(mode_number == controller_idle_mode){
		motor_controller1->setState(idle);
		motor_controller2->setState(idle);
		motor_controller3->setState(idle);
		this->mode = controller_idle_mode;
	}else if(mode_number == controller_running_mode){
		motor_controller1->setState(running);
		motor_controller2->setState(running);
		motor_controller3->setState(running);
		this->mode = controller_running_mode;
	}else if(mode_number == controller_calibrating_mode){
		printf("Start calibrating\n");
		motor_controller1->calibrate();
		//motor_controller2->calibrate();
		//motor_controller3->calibrate();

		printf("Calibrating done \n");
		set_controller_mode(controller_idle_mode);

	}
}

