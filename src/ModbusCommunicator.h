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
#include "DIO.h"
#include "FingerController.h"
#include <pthread.h>

#define BaudRate 19200
#define DataBit 8

#define SlaveAdress 1

class ModbusCommunicator{
public:
	ModbusCommunicator(FingerController *fingerController);
    void run();
    void start_thread();

    static void *run_helper(void *context)
    {
        ModbusCommunicator *mc = (ModbusCommunicator *)context;
        printf("TEST: %s \n", mc->uart.name);
        mc->run();
        return NULL;
    }

    static void start_thread(FingerController *fingerController){
        pthread_t t;
        pthread_create(&t, NULL, &ModbusCommunicator::start_modbus, fingerController);
    }

    static void *start_modbus(void *context){
        FingerController *fc = (FingerController *)context;
    	ModbusCommunicator *mc = new ModbusCommunicator(fc);
    	mc->run();
    }

    MyRio_Uart uart;
	MyRio_Dio writePin;
	FingerController *fingerController;

    void parseMessage(char *message, int length);
    static short calculateLRC(char *message, int start, int end);
    void readHoldingRegister(char *message, int length);
    void sendData(char *data, int length);

    void enableTX();
    void enableRX();

	int *holdingRegisters[3];
};

#endif /* I2CCOMMUNICATOR_H_ */
