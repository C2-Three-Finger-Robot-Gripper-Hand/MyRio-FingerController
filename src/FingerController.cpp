/*
 * FingerController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "FingerController.h"
#include <stdio.h>
#include <unistd.h>
#include "DIO.h"
#include "AIO.h"

FingerController::FingerController(){
	printf("Projectgroep C2 - Finger controller");
	printf("\n");

	motor_1 = new Motor(motor1_enable_pin, motor1_direction_pin, motor1_speed_pin);
	motor_1->enable();
	motor_1->forwards();
	motor_1->set_speed(100);

	printf("Setup done \n");
	for(;;){
		sleep(1);
	}
}
