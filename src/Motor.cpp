/*
 * Motor.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "Motor.h"
#include "DIO.h"
#include "AIO.h"
#include <stdio.h>

Motor::Motor(MyRio_Dio enable_pin, MyRio_Dio direction_pin, MyRio_Aio speed_pin){
	this->enable_pin = enable_pin;
	this->direction_pin = direction_pin;
	this->speed_pin = speed_pin;

	//Disable motor
	disable();

	//Forward motor
	forwards();

	//Set speed to zero
    Aio_Scaling(&this->speed_pin);
    set_speed(0);



//
//    //Test code hieronder
//	//Dit is Connector B - AO1
//    MyRio_Aio speed_pin2;
//    speed_pin2.val = AOB_1VAL;
//    speed_pin2.wght = AOB_1WGHT;
//    speed_pin2.ofst = AOB_1OFST;
//    speed_pin2.set = AOSYSGO;
//    speed_pin2.is_signed = NiFpga_True;
//    Aio_Scaling(&speed_pin2);
//	Aio_Write(&speed_pin2, 2);
//
//	//Dit is Connector A - AO0
//    MyRio_Aio speed_pin3;
//    speed_pin3.val = AOA_0VAL;
//    speed_pin3.wght = AOA_0WGHT;
//    speed_pin3.ofst = AOA_0OFST;
//    speed_pin3.set = AOSYSGO;
//    speed_pin3.is_signed = NiFpga_True;
//    Aio_Scaling(&speed_pin3);
//	Aio_Write(&speed_pin3, 3);
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
	forward = NiFpga_True;
    Dio_WriteBit(&direction_pin, forward);
}

void Motor::backwards(){
	forward = NiFpga_False;
    Dio_WriteBit(&direction_pin, forward);
}
