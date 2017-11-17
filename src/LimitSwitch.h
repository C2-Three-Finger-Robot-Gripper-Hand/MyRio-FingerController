/*
 * LimitSwitch.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef LIMITSWITCH_H_
#define LIMITSWITCH_H_

#include "DIO.h"

typedef struct{
	 MyRio_Dio switch_pin;
} LimitSwitch_Config;

class LimitSwitch{
public:
	LimitSwitch(const LimitSwitch_Config *limitSwitch_config);
	NiFpga_Bool hasReachedLimit();
private:
	NiFpga_Bool reachedLimit;
	MyRio_Dio pin;
};

#endif /* LIMITSWITCH_H_ */
