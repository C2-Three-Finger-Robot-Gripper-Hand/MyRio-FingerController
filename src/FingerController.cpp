/*
 * FingerController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "FingerController.h"
#include <stdio.h>
#include <unistd.h>

FingerController::FingerController(){
	printf("Projectgroep C2 - Finger controller");
	printf("\n");

	motor_1 = new Motor();
	motor_1->enable_motor();
	motor_1->set_speed(-50);

	printf("Setup done \n");
	for(;;){
		sleep(1);
	}
}
