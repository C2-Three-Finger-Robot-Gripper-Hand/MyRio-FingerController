/*
 * I2CCommunicator.h
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#ifndef MODBUSCOMMUNICATOR_H_
#define MODBUSCOMMUNICATOR_H_

#include <stdio.h>
#include <time.h>
#include "UART.h"

#define BaudRate 19200
#define DataBit 8

#define SlaveAdress 1

class ModbusCommunicator{
public:
	ModbusCommunicator();

private:
    MyRio_Uart uart;
};



#endif /* I2CCOMMUNICATOR_H_ */
