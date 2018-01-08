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

	set_controller_mode(controller_calibrating_mode);
	for(;;){
		modbus_controller->run();

		if (motor_controller1->currentState == controller_running_mode) {
			motor_controller1->run(false);
		}

		if (motor_controller2->currentState == controller_running_mode) {
			motor_controller2->run(false);
		}

		if (motor_controller3->currentState == controller_running_mode) {
			motor_controller3->run(false);
		}
		if (mode == controller_calibrating_mode) {

			if (!motor_controller1->isCalibrated()) {
				printf("calibrating motor 1\n");
				motor_controller1->calibrate();
			}
			else if (!motor_controller2->isCalibrated()) {
				printf("calibrating motor 2\n");
				motor_controller2->calibrate();

				if (motor_controller1->currentState != controller_running_mode) {
					printf("set motor 1 to running mode\n");
					motor_controller1->setState(controller_running_mode);
					motor_controller1->setMotorPosition(90.0);
				}
			}
			else if (!motor_controller3->isCalibrated()) {
				printf("calibrating motor 3\n");
				motor_controller3->calibrate();

				if (motor_controller2->currentState != controller_running_mode) {
					printf("set motor 2 to running mode\n");
					motor_controller2->setState(controller_running_mode);
					motor_controller2->setMotorPosition(90.0);
				}
			}
			else {
				printf("calibration done\n");
				if (motor_controller3->currentState != controller_running_mode) {
					printf("set motor 3 to running mode\n");
					motor_controller3->setState(controller_running_mode);
					motor_controller3->setMotorPosition(90.0);
				}
				this->set_controller_mode(controller_running_mode);
			}
		}
	}
}

void FingerController::set_controller_mode(double mode_number){
	printf("mode number: %f, calibrating mode: %u", mode_number, controller_calibrating_mode);

	if(mode_number == controller_idle_mode){
		motor_controller1->setState(controller_idle_mode);
		motor_controller2->setState(controller_idle_mode);
		motor_controller3->setState(controller_idle_mode);
		this->mode = controller_idle_mode;
	}else if(mode_number == controller_running_mode){
		motor_controller1->setState(controller_running_mode);
		motor_controller2->setState(controller_running_mode);
		motor_controller3->setState(controller_running_mode);
		this->mode = controller_running_mode;
	}else if(mode_number == controller_calibrating_mode){
		motor_controller1->setState(controller_calibrating_mode);
		motor_controller2->setState(controller_calibrating_mode);
		motor_controller3->setState(controller_calibrating_mode);
		this->mode = controller_calibrating_mode;
	}
}

