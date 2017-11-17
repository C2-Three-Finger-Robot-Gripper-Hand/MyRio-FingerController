/*
 * LimitSwitch.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "LimitSwitch.h"

LimitSwitch::LimitSwitch(){
	this->ishigh = NiFpga_False;

	this->pin.dir = DIOB_70DIR;
	this->pin.out = DIOB_70OUT;
	this->pin.in = DIOB_70IN;
	this->pin.bit = 10;
}

bool LimitSwitch::isHigh() {
	return Dio_ReadBit(&this->pin);
}


