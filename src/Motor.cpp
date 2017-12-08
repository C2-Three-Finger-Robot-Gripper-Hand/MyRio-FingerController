/*
 * Motor.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "Motor.h"

Motor::Motor(const Motor_Config *config){
	this->enable_pin = config->enable_pin;
	this->direction_pin = config->direction_pin;
	this->speed_pin = config->speed_pin;

	//Disable motor
	disable();

	//Forward motor
	forwards();

	//Set speed to zero
    Aio_Scaling(&this->speed_pin);
    set_speed(0);
}

void Motor::set_speed(double speed){
	if(speed >= 0 && speed <= 100){
		current_speed = speed;
		Aio_Write(&speed_pin, speed/20.f);
	}
}

void Motor::enable(){
	is_enabled = NiFpga_True;
    Dio_WriteBit(&enable_pin, is_enabled);
}

void Motor::disable(){
	is_enabled = NiFpga_False;
    Dio_WriteBit(&enable_pin, is_enabled);
}

void Motor::forwards(){
	direction = Forwards;
    Dio_WriteBit(&direction_pin, direction);
}

void Motor::backwards(){
	direction = Backwards;
    Dio_WriteBit(&direction_pin, direction);
}
