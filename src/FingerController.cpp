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

	motor_1 = new Motor(&MOTOR1_CONFIG);
	motor_1->disable();
	motor_1->forwards();
	motor_1->set_speed(50);

	motor_2 = new Motor(&MOTOR2_CONFIG);
	motor_2->disable();
	motor_2->forwards();
	motor_2->set_speed(50);

	motor_3 = new Motor(&MOTOR3_CONFIG);
	motor_3->disable();
	motor_3->forwards();
	motor_3->set_speed(50);

	printf("Setup done \n");
	for(;;){
		sleep(1);
	}
}
