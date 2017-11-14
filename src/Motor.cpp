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

Motor::Motor(){
	//Setup enable pin
	enable_pin.dir = DIOA_70DIR;
	enable_pin.out = DIOA_70OUT;
	enable_pin.in = DIOA_70IN;
	enable_pin.bit = 0;

	//Disable motor
	disable_motor();

	//Setup analog output pin
    speed_pin.val = AOB_0VAL;
    speed_pin.wght = AOB_0WGHT;
    speed_pin.ofst = AOB_0OFST;
    speed_pin.set = AOSYSGO;
    speed_pin.is_signed = NiFpga_True;
    Aio_Scaling(&speed_pin);
}

void Motor::set_speed(signed char speed){
	if(speed >= -100 && speed <= 100){
		current_speed = speed;
		Aio_Write(&speed_pin, speed/10);
	}
}

void Motor::enable_motor(){
	is_enabled = NiFpga_True;
    Dio_WriteBit(&enable_pin, is_enabled);
}

void Motor::disable_motor(){
	is_enabled = NiFpga_False;
    Dio_WriteBit(&enable_pin, is_enabled);
}

