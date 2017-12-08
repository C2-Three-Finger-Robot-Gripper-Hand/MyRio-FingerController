/*
 * MotorController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "MotorController.h"
#include <unistd.h>
#include "FingerController.h"
#include <stdio.h>

MotorController::MotorController(const Motor_Config *motor_config, const Encoder_Config *encoder_config, const LimitSwitch_Config *end_switch_1, const LimitSwitch_Config *end_switch_2){
	this->motor = new Motor(motor_config);
	this->encoder = new RotaryEncoder(encoder_config);
	this->end_switch_1 = new LimitSwitch(end_switch_1);
	this->end_switch_2 = new LimitSwitch(end_switch_2);
	this->motorPid = new PID(1.0/TICKS_PER_SECOND, 100.0, -100.0, 0.008, 0.0003, 0.008);
	this->maxSteps = -1;
	this->isCalibrated = NiFpga_False;
	this->currentState = idle;
	this->requestedMotorPosition = 0.0;
	this->currentMotorPosition = 0.0;
}

void MotorController::setState(MotorControllerState state){
	if(state == idle){
		this->currentState = idle;
		this->motor->disable();
	}else if(state == running && isCalibrated){
		printf("Switching to running state \n");
		this->currentState = running;
		this->motor->enable();
	}
}

void MotorController::run(){
	if(currentState == running){
		double requestedMotorPositionInStep = (this->requestedMotorPosition / MOTOR_POSITION_MAX) * this->maxSteps;

		uint32_t currentSteps = encoder->readSteps();
		//calculate motor speed to reach request motor position
        double motorSpeed = motorPid->calculate(requestedMotorPositionInStep/10, (int)currentSteps/10);

        //calculate current motor position in degree
        this->currentMotorPosition = MOTOR_POSITION_MAX * currentSteps / (double)this->maxSteps;

//        printf("Speed: %f Current Steps: %zu Requested position step: %f Motor position(degree)%f\n", motorSpeed, currentSteps, requestedMotorPositionInStep, this->currentMotorPosition);
        if(motorSpeed >= 0){
        	motor->set_speed(motorSpeed);
        	motor->backwards();
        }else{
        	motor->set_speed(-1*motorSpeed);
        	motor->forwards();
        }
	}else if(currentState == calibrating){

	}
}

void MotorController::calibrate() {
	this->motor->set_speed(20);

	/*rotating to end switch 2*/
	this->motor->forwards();
	this->motor->enable();

	printf("Going to switch 2\n");
	while(!this->end_switch_2->hasReachedLimit()) {
		usleep(1000);
	}
	this->motor->disable();
	printf("encoder value: %d\n", this->encoder->readSteps());
	printf("Reached endswitch 2\n");

	this->encoder->resetSteps();

	/*rotating to end switch 1, to get steps*/
	this->motor->backwards();
	this->motor->enable();

	while(!this->end_switch_1->hasReachedLimit()) {
		usleep(1000);
	}
	printf("encoder value: %d\n", this->encoder->readSteps());
	printf("Reached endswitch 1\n");

	this->motor->disable();
	this->maxSteps = this->encoder->readSteps();
	this->isCalibrated = NiFpga_True;
	this->setMotorPosition(MOTOR_POSITION_MAX/2);
	printf("Max steps: %d\n", this->maxSteps);
}

void MotorController::setMotorPosition(double degree) {
	if (this->isCalibrated) {
		if (degree < MOTOR_POSITION_MIN) degree = MOTOR_POSITION_MIN;
		if (degree > MOTOR_POSITION_MAX) degree = MOTOR_POSITION_MAX;

		this->requestedMotorPosition = degree;
	}
}

MotorController::~MotorController(){
    this->motor->disable();
    this->motor->backwards();
    this->motor->set_speed(0);
}




