/*
 * Motor.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef MOTOR_H_
#define MOTOR_H_

#include "DIO.h"
#include "AIO.h"

class Motor{
public:
	Motor();
	void enable_motor();
	void disable_motor();
	void set_speed(signed char speed);
private:
	MyRio_Dio enable_pin;
	NiFpga_Bool is_enabled;

	MyRio_Aio speed_pin;
	signed char current_speed;
};

#endif /* MOTOR_H_ */
