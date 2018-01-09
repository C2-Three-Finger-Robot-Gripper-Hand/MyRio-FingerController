/*
 * I2CCommunicator.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

#include "MotorController.h"
#include "ModbusCommunicator.h"
#include "string.h"
#include "DIO.h"

ModbusCommunicator::ModbusCommunicator(FingerController *fingerController){
    this->fingerController = fingerController;
	this->writePin = {NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT2, 2};

    /*
     * Initialize holding register references
     */
	holdingRegisters[0] = &this->fingerController->motor_controller1->currentMotorPosition;
	holdingRegisters[1] = &this->fingerController->motor_controller2->currentMotorPosition;
	holdingRegisters[2] = &this->fingerController->motor_controller3->currentMotorPosition;
	holdingRegisters[3] = &this->fingerController->mode;

    /*
     * Initialize writing register references
     */
	using namespace std::placeholders;
	writingRegisters[0] = std::bind(&MotorController::setMotorPosition, this->fingerController->motor_controller1, _1);
	writingRegisters[1] = std::bind(&MotorController::setMotorPosition, this->fingerController->motor_controller2, _1);
	writingRegisters[2] = std::bind(&MotorController::setMotorPosition, this->fingerController->motor_controller3, _1);
	writingRegisters[3] = std::bind(&FingerController::set_controller_mode, this->fingerController, _1);

    /*;
     * Initialize the UART port structure.
     */
    uart.name = "ASRL1::INSTR";
    uart.defaultRM = 0;
    uart.session = 0;

    /*
     * Opens a UART session.
     */
    Uart_Open(&uart, BaudRate, DataBit, Uart_StopBits1_0, Uart_ParityNone);
}

void ModbusCommunicator::run(){
	ViUInt32 read_count = 0;
	int32_t status = 0;

    enableRX();
    memset(buf, 0, sizeof(char)*254);
	status = Uart_Read(&uart, buf, 254, &read_count);
	if (status != VI_ERROR_TMO){
		for(int i = 0; i < (long)read_count; i++){
			if(buf[i] == ':'){		//New message, discard old message
				memset(message, 0, sizeof(char)*254);
				position = 0;
			}else if(buf[i] == '\n'){	//Message ended.
				message[position] = '\0';
				printf("Message received!: %s \n", message);
				parseMessage(message, position);
				printf("\n\n");
			}else if(buf[i] != '\r'){
				message[position] = buf[i];
				position++;
			}
		}
	}
}

void ModbusCommunicator::parseMessage(char *message, int length){
	short lrc_calc = ModbusCommunicator::calculateLRC(message, 0, length-2);

	int adress = convert_slice(message, 0, 2);
	int function = convert_slice(message, 2, 4);
	int lrc = convert_slice(message, length-2, length);


	printf("Address: %d Function code: %d LRC: %d Calculated LRC %d \n", adress, function, lrc, lrc_calc);
	if(lrc == lrc_calc && adress == SlaveAdress){ //Message located to us
		if(function == 3){
			readHoldingRegister(message, length);
		}else if(function == 16){
			writeHoldingRegister(message, length);
		}
	}
}

void ModbusCommunicator::writeHoldingRegister(char *message, int length){
	int startAdress = convert_slice(message, 4, 8);
	int registerQuantity = convert_slice(message, 8, 12);
	int dataLength = convert_slice(message, 12, 14) * 2;

	printf("Write holding register from %d and a number of %d with a datalength of %d \n", startAdress, registerQuantity, dataLength);

	char data[10] = {0};
	data[0] = '1';								//Function code
	data[1] = '0';								//Function code
    sprintf(&data[2], "%04x", startAdress);		//Starting address
    sprintf(&data[6], "%04x", registerQuantity);//Quantity registers

    sendData(data, 10);

	//Writing to registers
    for(int i = 0; i < registerQuantity; i++){
    	int registerNumber = startAdress + i;
    	if(registerNumber < NUMBER_OF_WRITE_REGISTERS){
        	int value = convert_slice(message, 14 + i * 4, 18 + i * 4);
        	printf("Writing to register %d value: %d\n", registerNumber, value);
        	writingRegisters[registerNumber]((double)value);
    	}
    }
}

void ModbusCommunicator::readHoldingRegister(char *message, int length){
	int startAdress = convert_slice(message, 4, 8);
	int registerQuantity = convert_slice(message, 8, 12);

	printf("Message received! NR2: %s \n", message);
	printf("Reading holding register from %d and a number of %d \n", startAdress, registerQuantity);

	int dataLength = 4 + registerQuantity * 4;
	char data[dataLength];
	data[0] = '0';								//Function code
	data[1] = '3';								//Function code
    sprintf(&data[2], "%02x", registerQuantity * 2);	//Byte count
    for(int i = 0; i < registerQuantity; i++){
    	int registerNumber = startAdress + i;
    	if(registerNumber < NUMBER_OF_HOLDING_REGISTERS){
    		//int value = holdingRegisters[registerNumber];
        	printf("Register value: %d\n",  *holdingRegisters[registerNumber]);
            sprintf(&data[4 + i * 4], "%04x", *holdingRegisters[registerNumber]);				// Register value
    	}
    }

    sendData(data, dataLength);

}

void ModbusCommunicator::sendData(char *data, int length){
	int msgLength = length + 7;
	char message[msgLength];
    memset(message, 0, sizeof(char)*msgLength);

	message[0] = ':';							//Start byte
    sprintf(&message[1], "%02x", SlaveAdress);	//Slave Address
    sprintf(&message[3], "%s", data);			//Data
    sprintf(&message[3+length], "%02x", calculateLRC(message, 1, length+3));	//LRC
    message[3+length+2] = '\r';					//End char
    message[3+length+3] = '\n';					//End char

    printf("Sending message: ");
    uint8_t message_uint8[msgLength];
    memset(message_uint8, 0, sizeof(uint8_t)*msgLength);

    for(int i = 0; i < msgLength ; i++){
        printf("%c", message[i]);
    	message_uint8[i] = message[i];
    }
    printf("\n");

    enableTX();

    Uart_Write(&uart, message_uint8, msgLength);

    enableRX();
}



void ModbusCommunicator::enableRX(){
    Dio_WriteBit(&writePin, NiFpga_False);
}

void ModbusCommunicator::enableTX(){
    Dio_WriteBit(&writePin, NiFpga_True);
}


//**
// Helper functions
//**

short ModbusCommunicator::calculateLRC(char *message, int start, int end){
	int lrc = 0;
	int fctr = 16;

	char buf[0];
	for (int i = start; i < end; i++){
		buf[0] = message[i];
	    int val = strtol(buf, NULL, 16);

		lrc += val * fctr;

        if (fctr == 16) fctr = 1;
        else            fctr = 16;
	}
	lrc = (~(lrc & 0xff) + 1) & 0xFF;
	return lrc;
}

int ModbusCommunicator::convert_slice(const char *s, size_t a, size_t b){
	char tmp[b - a + 1];
	strncpy(tmp, s+a, b-a);
	tmp[b-a] = '\0';
    return (int)strtol(tmp, NULL, 16);
}
