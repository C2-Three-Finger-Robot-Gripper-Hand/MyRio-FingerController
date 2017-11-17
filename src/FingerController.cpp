/*
 * FingerController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "FingerController.h"
#include <stdio.h>
#include "DIO.h"
#include "AIO.h"
#include "RotaryEncoder.h"
#include "LimitSwitch.h"
#include <unistd.h>

FingerController::FingerController(){
	printf("Projectgroep C2 - Finger controller");
	printf("\n");

//	motor1_encoder = new RotaryEncoder(&MOTOR1_ENCODER_CONFIG);
//	motor2_encoder = new RotaryEncoder(&MOTOR2_ENCODER_CONFIG);
//	motor3_encoder = new RotaryEncoder(&MOTOR3_ENCODER_CONFIG);
//
//	motor_1 = new Motor(&MOTOR1_CONFIG);
//	motor_1->disable();
//	motor_1->forwards();
//	motor_1->set_speed(50);
//
//	motor_2 = new Motor(&MOTOR2_CONFIG);
//	motor_2->enable();
//	motor_2->disable();
//	motor_2->set_speed(50);
//
//	motor_3 = new Motor(&MOTOR3_CONFIG);
//	motor_3->disable();
//	motor_3->forwards();
//	motor_3->set_speed(50);

	LimitSwitch Diob10;

	printf("Setup done \n");
	for(;;){
//		uint32_t steps1 = motor1_encoder->readSteps();
//		uint32_t steps2 = motor2_encoder->readSteps();
//		uint32_t steps3 = motor3_encoder->readSteps();
//
//		printf("Steps enc 1 %d, Steps enc 2 %d, Steps enc 3 %d\n", steps1, steps2, steps3);

		printf("Reading...\n");
		bool isHigh = Diob10.isHigh();

		printf("Diob10 is high: %d\n", isHigh);
		sleep(1);
	}
}
