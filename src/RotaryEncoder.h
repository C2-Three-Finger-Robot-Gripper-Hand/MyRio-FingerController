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
	uint32_t      indicator;
	uint8_t	      indicator_enable_bit;
} Encoder_Config;

class IRotaryEncoder{
public:
	virtual ~IRotaryEncoder(){}
	virtual uint32_t readSteps() = 0;
};

class QuadratureCounterEncoder : public IRotaryEncoder{
public:
	QuadratureCounterEncoder(const Encoder_Config *encoder_config);
	virtual uint32_t readSteps();
private:
    MyRio_Encoder encoder;
	uint32_t steps;
	const char* direction;
};

class FPGACounterEncoder : public IRotaryEncoder{
public:

};

#endif /* ROTARYENCODER_H_ */
