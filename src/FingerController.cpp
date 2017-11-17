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

//	LimitSwitch Diob10;

	motor_controller1 = new MotorController(&MOTOR1_CONFIG, &MOTOR1_ENCODER_CONFIG,
			&MOTOR3_END_SWITCH1_CONFIG, &MOTOR3_END_SWITCH2_CONFIG);

	motor_controller2 = new MotorController(&MOTOR2_CONFIG, &MOTOR2_ENCODER_CONFIG,
				&MOTOR3_END_SWITCH1_CONFIG, &MOTOR3_END_SWITCH2_CONFIG);

	motor_controller3 = new MotorController(&MOTOR3_CONFIG, &MOTOR3_ENCODER_CONFIG,
					&MOTOR3_END_SWITCH1_CONFIG, &MOTOR3_END_SWITCH2_CONFIG);

	printf("Setup done \n");
	for(;;){
		uint32_t steps1 = motor_controller1->encoder->readSteps();
		uint32_t steps2 = motor_controller2->encoder->readSteps();
		uint32_t steps3 = motor_controller3->encoder->readSteps();

		printf("Steps enc 1 %d, Steps enc 2 %d, Steps enc 3 %d\n", steps1, steps2, steps3);

		printf("Limitswitchses are reached -> %d : %d", motor_controller3->end_switch_1->hasReachedLimit(), motor_controller3->end_switch_2->hasReachedLimit());
		sleep(1);
	}
}
