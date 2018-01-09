/*
 * States.h
 *
 *  Created on: 13 dec. 2017
 *      Author: remco
 */

#ifndef STATES_H_
#define STATES_H_

typedef enum{
	controller_running_mode,
	controller_idle_mode,
	controller_calibrating_mode
} controller_state;

typedef enum{
	calibrating_not_done,
	calibrating_end_switch_1,
	calibrating_end_switch_2,
	calibrating_done
} Calibrating;

#endif /* STATES_H_ */
