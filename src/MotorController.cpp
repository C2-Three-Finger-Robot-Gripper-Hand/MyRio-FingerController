/*
 * MotorController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "MotorController.h"

MotorController::MotorController(const Motor_Config *motor_config, const Encoder_Config *encoder_config, const LimitSwitch_Config *end_switch_1, const LimitSwitch_Config *end_switch_2){
	this->motor = new Motor(motor_config);
	this->encoder = new RotaryEncoder(encoder_config);
	this->end_switch_1 = new LimitSwitch(end_switch_1);
	this->end_switch_2 = new LimitSwitch(end_switch_2);
}

MotorController::~MotorController(){
    this->motor->disable();
    this->motor->backwards();
    this->motor->set_speed(0);
}





