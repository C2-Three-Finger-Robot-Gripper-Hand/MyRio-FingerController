/*
 * LimitSwitch.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "LimitSwitch.h"

LimitSwitch::LimitSwitch(const LimitSwitch_Config *limitSwitch_config){
	this->reachedLimit = NiFpga_False;
	this->pin = limitSwitch_config->switch_pin;
}

NiFpga_Bool LimitSwitch::hasReachedLimit() {
	this->reachedLimit = !Dio_ReadBit(&this->pin);
	return this->reachedLimit;
}


