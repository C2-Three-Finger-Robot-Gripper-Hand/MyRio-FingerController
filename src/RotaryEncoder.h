/*
 * RotaryEncoder.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Janco
 */

#ifndef ROTARYENCODER_H_
#define ROTARYENCODER_H_

#include "MyRio.h"
#include "Encoder.h"

typedef struct{
	MyRio_Encoder encoder;
} Encoder_Config;

enum Rotary_Encoder_Direction{
	Incrementing,
	Decrementing
};

class RotaryEncoder{
public:
	RotaryEncoder(const Encoder_Config *encoder_config);
	~RotaryEncoder(){}
	uint32_t readSteps();
	void resetSteps();
	uint32_t steps;
    MyRio_Encoder encoder;
	Rotary_Encoder_Direction direction;
};

#endif /* ROTARYENCODER_H_ */
