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
	SYSSELECTB
};

const Encoder_Config MOTOR2_ENCODER_CONFIG = {
	{ENCACNFG, ENCASTAT, ENCACNTR},
	SYSSELECTA
};

class FingerController {
public:
	FingerController();
	IRotaryEncoder *motor1_encoder;
	IRotaryEncoder *motor2_encoder;
};


#endif /* FINGERCONTROLLER_H_ */
