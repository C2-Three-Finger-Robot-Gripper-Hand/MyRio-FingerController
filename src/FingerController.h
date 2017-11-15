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

const MyRio_Dio motor1_enable_pin = {
		DIOB_70DIR,
		DIOB_70OUT,
		DIOB_70IN,
		0
};
const MyRio_Dio motor1_direction_pin = {
		DIOB_70DIR,
		DIOB_70OUT,
		DIOB_70IN,
		1
};
const MyRio_Aio motor1_speed_pin = {
	   AOB_0VAL,
	   AOB_0WGHT,
	   AOB_0OFST,
	   AOSYSGO,
	   NiFpga_True
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
