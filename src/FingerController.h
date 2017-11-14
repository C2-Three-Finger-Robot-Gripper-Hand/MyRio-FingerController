/*
 * FingerController.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef FINGERCONTROLLER_H_
#define FINGERCONTROLLER_H_

#include "Motor.h"

class FingerController {
public:
	FingerController();
private:
	Motor *motor_1;
	Motor *motor_2;
	Motor *motor_3;
};


#endif /* FINGERCONTROLLER_H_ */
