/*
 * FingerController.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "FingerController.h"
#include <stdio.h>
#include "RotaryEncoder.h"
#include <unistd.h>

FingerController::FingerController(){
	printf("TEST\n");
	motor1_encoder = new QuadratureCounterEncoder(&MOTOR1_ENCODER_CONFIG);
	motor2_encoder = new QuadratureCounterEncoder(&MOTOR2_ENCODER_CONFIG);

	for(;;){
		uint32_t steps1 = motor1_encoder->readSteps();
		uint32_t steps2 = motor2_encoder->readSteps();
		printf("Steps enc 1 %d, Steps enc 2 %d\n", steps1, steps2);
		sleep(1);
	}
}
