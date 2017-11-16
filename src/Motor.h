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

typedef struct{
	 MyRio_Dio enable_pin;
	 MyRio_Dio direction_pin;
	 MyRio_Aio speed_pin;
} Motor_Config;

class Motor{
public:
	Motor(const Motor_Config *config);
	void enable();
	void disable();
	void set_speed(double speed);
	void forwards();
	void backwards();
private:
	MyRio_Dio enable_pin;
	MyRio_Dio direction_pin;

	NiFpga_Bool is_enabled;
	NiFpga_Bool forward;

	MyRio_Aio speed_pin;
	double current_speed;
};

#endif /* MOTOR_H_ */
