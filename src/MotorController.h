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

#define MOTOR_POSITION_MAX 180.0
#define MOTOR_POSITION_MIN 0.0

enum MotorControllerState{
	idle,
	running,
	calibrating,
};

class MotorController{
public:
	MotorController(const Motor_Config *motor_config, const Encoder_Config *encoder_config, const LimitSwitch_Config *end_switch_1, const LimitSwitch_Config *end_switch_2);
	~MotorController();

	PID * motorPid;
	/*
	 * Motor Forwards goes to end_switch_1
	 * Motor Backwards goes to end_switch_2
	 * */
	Motor* motor;
	RotaryEncoder* encoder;
	LimitSwitch* end_switch_1;
	LimitSwitch* end_switch_2;

	void run();
	void calibrate();
	void setState(MotorControllerState state);
	void setMotorPosition(double degree);
	double requestedMotorPosition;
	double currentMotorPosition;
private:
	MotorControllerState currentState;
	uint32_t maxSteps;
	NiFpga_Bool isCalibrated;
};

#endif /* MOTORCONTROLLER_H_ */
