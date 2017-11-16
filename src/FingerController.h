/*
 * FingerController.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef FINGERCONTROLLER_H_
#define FINGERCONTROLLER_H_

#include "Motor.h"
#include "DIO.h"
#include "AIO.h"

const Motor_Config MOTOR1_CONFIG = {
		{DIOB_70DIR, DIOB_70OUT, DIOB_70IN, 0},
		{DIOB_70DIR, DIOB_70OUT, DIOB_70IN, 1},
		{AOB_0VAL, AOB_0WGHT, AOB_0OFST, AOSYSGO, NiFpga_True}
};

const Motor_Config MOTOR2_CONFIG = {
		{DIOB_70DIR, DIOB_70OUT, DIOB_70IN, 2},
		{DIOB_70DIR, DIOB_70OUT, DIOB_70IN, 3},
		{AOB_1VAL, AOB_1WGHT, AOB_1OFST, AOSYSGO, NiFpga_True}
};

const Motor_Config MOTOR3_CONFIG = {
		{DIOB_70DIR, DIOB_70OUT, DIOB_70IN, 4},
		{DIOB_70DIR, DIOB_70OUT, DIOB_70IN, 5},
		{AOA_0VAL, AOA_0WGHT, AOA_0OFST, AOSYSGO, NiFpga_True}
};

class FingerController {
public:
	FingerController();
private:
	Motor *motor_1;
	Motor *motor_2;
	Motor *motor_3;
};


#endif /* FINGERCONTROLLER_H_ */
