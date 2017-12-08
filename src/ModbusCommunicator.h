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
#include <pthread.h>
#include <functional>

#include "UART.h"
#include "DIO.h"
#include "FingerController.h"

#define BaudRate 115200
#define DataBit 8

#define SlaveAdress 1

#define NUMBER_OF_HOLDING_REGISTERS 3
#define NUMBER_OF_WRITE_REGISTERS 3
typedef std::function<void(double)> WriteRegisterPointer;


class ModbusCommunicator{
public:
	ModbusCommunicator(FingerController *fingerController);
    void run();

private:
    MyRio_Uart uart;
	MyRio_Dio writePin;
	FingerController *fingerController;

	int *holdingRegisters[NUMBER_OF_HOLDING_REGISTERS];
	WriteRegisterPointer writingRegisters[NUMBER_OF_WRITE_REGISTERS];

	char message[254] = {0};
    int position = 0;
	char buf[254];


    void parseMessage(char *message, int length);
    void readHoldingRegister(char *message, int length);
    void writeHoldingRegister(char *message, int length);
    void sendData(char *data, int length);

    void enableTX();
    void enableRX();


	//Helper functions
    static short calculateLRC(char *message, int start, int end);
    static int convert_slice(const char *s, size_t a, size_t b);
};

#endif /* I2CCOMMUNICATOR_H_ */
