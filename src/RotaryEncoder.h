/*
 * IRotaryEncoder.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Janco
 */

#ifndef ROTARYENCODER_H_
#define ROTARYENCODER_H_

class IRotaryEncoder{
public:
	virtual ~IRotaryEncoder(){}
	virtual void OvverrideMe() = 0;
};

class QuadratureCounterEncoder : public IRotaryEncoder{
public:

};

class FPGACounterEncoder : public IRotaryEncoder{
public:

};

#endif /* ROTARYENCODER_H_ */
