/*
 * FingerController.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef FINGERCONTROLLER_H_
#define FINGERCONTROLLER_H_

#include "Encoder.h"
#include "RotaryEncoder.h"

const Encoder_Config MOTOR1_ENCODER_CONFIG = {
	{ENCBCNFG, ENCBSTAT, ENCBCNTR},
	SYSSELECTB,
	5
};

const Encoder_Config MOTOR2_ENCODER_CONFIG = {
	{ENCACNFG, ENCASTAT, ENCACNTR},
	SYSSELECTA,
	5
};

const Encoder_Config MOTOR3_ENCODER_CONFIG = {
	{ENCC_0CNFG, ENCC_0STAT, ENCC_0CNTR},
	SYSSELECTC,
	0
};


class FingerController {
public:
	FingerController();
	RotaryEncoder *motor1_encoder;
	RotaryEncoder *motor2_encoder;
	RotaryEncoder *motor3_encoder;
};


#endif /* FINGERCONTROLLER_H_ */
