/*
 * MotorController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "MotorController.h"
#include <unistd.h>

MotorController::MotorController(const Motor_Config *motor_config, const Encoder_Config *encoder_config, const LimitSwitch_Config *end_switch_1, const LimitSwitch_Config *end_switch_2){
	this->motor = new Motor(motor_config);
	this->encoder = new RotaryEncoder(encoder_config);
	this->end_switch_1 = new LimitSwitch(end_switch_1);
	this->end_switch_2 = new LimitSwitch(end_switch_2);
	this->motorPid = new PID(0.1, 100, -100, 0.1, 0.01, 0.5);
	this->max_steps = -1;

	currentState = idle;
}

void MotorController::run(){
	if(currentState == running){
		//hardcoded 9000 steps
        double motorSpeed = motorPid->calculate(9000, encoder->readSteps());
        if(motorSpeed >= 0){
        	motor->set_speed(motorSpeed);
        	motor->forwards();
        }else{
        	motor->set_speed(-1*motorSpeed);
        	motor->backwards();
        }
	}else if(currentState == calibrating){

	}
}


void MotorController::calibrate() {
	this->motor->set_speed(20);

	/*rotating to end switch 2*/
	this->motor->forwards();
	this->motor->enable();

	while(!this->end_switch_2->hasReachedLimit()) {
		usleep(1000);
	}
	this->motor->disable();
//	printf("encoder value: %d\n", this->encoder->readSteps());
//	printf("Reached endswitch 2\n");

	this->encoder->resetSteps();

	/*rotating to end switch 1, to get steps*/
	this->motor->backwards();
	this->motor->enable();

	while(!this->end_switch_1->hasReachedLimit()) {
		usleep(1000);
	}
	this->motor->disable();
	this->max_steps = this->encoder->readSteps();
	this->isCalibrated = NiFpga_True;
//
//	printf("Reached endswitch 1\n");
//	printf("Max steps: %d\n", this->max_steps);
}

MotorController::~MotorController(){
    this->motor->disable();
    this->motor->backwards();
    this->motor->set_speed(0);
}




