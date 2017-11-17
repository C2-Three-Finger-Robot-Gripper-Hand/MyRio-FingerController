/*
 * LimitSwitch.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_

#include "DIO.h"

class LimitSwitch{
public:
	LimitSwitch(MyRio_Dio pin);
	bool isHigh();
private:
	NiFpga_Bool ishigh;
	MyRio_Dio pin;
};

#endif /* LIMITSWITCH_H_ */
