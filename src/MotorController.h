/*
 * MotorController.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef MOTORCONTROLLER_H_
#define MOTORCONTROLLER_H_

#include "Motor.h"
#include "RotaryEncoder.h"
#include "LimitSwitch.h"
#include "Pid.h"

enum MotorControllerState{
	idle,
	running,
	calibrating,
};

class MotorController{
public:
	MotorController(const Motor_Config *motor_config, const Encoder_Config *encoder_config, const LimitSwitch_Config *end_switch_1, const LimitSwitch_Config *end_switch_2);

	PID * motorPid;
	Motor* motor;
	RotaryEncoder* encoder;
	LimitSwitch* end_switch_1;
	LimitSwitch* end_switch_2;

	void run();
private:
	MotorControllerState currentState;
};

#endif /* MOTORCONTROLLER_H_ */
