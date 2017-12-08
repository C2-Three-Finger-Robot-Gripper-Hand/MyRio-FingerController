/*
 * FingerController.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */


#ifndef FINGERCONTROLLER_H_
#define FINGERCONTROLLER_H_

#define TICKS_PER_SECOND 100

#include "MotorController.h"

/*Rotary encoder configs*/
const Encoder_Config MOTOR1_ENCODER_CONFIG = {
	{   NiFpga_FPGAMainDefault_ControlU8_ENC1CNFG,
		NiFpga_FPGAMainDefault_IndicatorU8_ENC1STAT,
		NiFpga_FPGAMainDefault_IndicatorU32_ENC1CNTR
	}
};

const Encoder_Config MOTOR2_ENCODER_CONFIG = {
	{   NiFpga_FPGAMainDefault_ControlU8_ENC2CNFG,
		NiFpga_FPGAMainDefault_IndicatorU8_ENC2STAT,
		NiFpga_FPGAMainDefault_IndicatorU32_ENC2CNTR
	}
};

const Encoder_Config MOTOR3_ENCODER_CONFIG = {
	{   NiFpga_FPGAMainDefault_ControlU8_ENC3CNFG,
		NiFpga_FPGAMainDefault_IndicatorU8_ENC3STAT,
		NiFpga_FPGAMainDefault_IndicatorU32_ENC3CNTR
	}
};

/*Motor configs*/
const Motor_Config MOTOR1_CONFIG = {
	{NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT1, 0},
	{NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT1, 1},
	{NiFpga_FPGAMainDefault_ControlU16_AOB_0VAL, AOB_0WGHT, AOB_0OFST}
};
//
const Motor_Config MOTOR2_CONFIG = {
	{NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT1, 2},
	{NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT1, 3},
	{NiFpga_FPGAMainDefault_ControlU16_AOB_1VAL, AOB_1WGHT, AOB_1OFST}
};

const Motor_Config MOTOR3_CONFIG = {
	{NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT2, 0},
	{NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT2, 1},
	{NiFpga_FPGAMainDefault_ControlU16_AOA_0VAL, AOA_0WGHT, AOA_0OFST}
};

/*Limitswitch configs*/
const LimitSwitch_Config MOTOR1_END_SWITCH1_CONFIG = {{NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN1,0}};
const LimitSwitch_Config MOTOR1_END_SWITCH2_CONFIG = {{NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN1,1}};

const LimitSwitch_Config MOTOR2_END_SWITCH1_CONFIG = {{NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN1,2}};
const LimitSwitch_Config MOTOR2_END_SWITCH2_CONFIG = {{NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN1,3}};

const LimitSwitch_Config MOTOR3_END_SWITCH1_CONFIG = {{NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN2,0}};
const LimitSwitch_Config MOTOR3_END_SWITCH2_CONFIG = {{NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN2,1}};

typedef enum{
	controller_running_mode,
	controller_idle_mode,
	controller_calibrating_mode
} controller_mode;

class FingerController {
public:
	FingerController();
	~ FingerController();

	void run();

	MotorController *motor_controller1;
	MotorController *motor_controller2;
	MotorController *motor_controller3;

	int mode;
	void set_controller_mode(double);
};


#endif /* FINGERCONTROLLER_H_ */
