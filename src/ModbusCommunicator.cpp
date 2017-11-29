/*
 * I2CCommunicator.cpp
 *
 *  Created on: Nov 8, 2017
 *      Author: Project team C2
 */

#include "ModbusCommunicator.h"
#include "string.h"

ModbusCommunicator::ModbusCommunicator(){
    uint8_t readData = 0;
    int32_t status = 0;

    /*
     * Initialize the UART port structure.
     */
    uart.name = "ASRL1::INSTR";
    uart.defaultRM = 0;
    uart.session = 0;

    /*
     * Opens a UART session.
     */
    Uart_Open(&uart, BaudRate, DataBit, Uart_StopBits1_0, Uart_ParityNone);

    /*
     * Reads data from a UART port.
     */
    char message[255] = {0};
    int position = 0;
    for(;;){
        status = Uart_Read(&uart, &readData, 1);
        if (status != VI_ERROR_TMO){
            printf("The received data is %c \n", readData);

            if(readData == ':'){		//New message, discard old message
            	memset(message, 0, sizeof message );
            	position = 0;
            }else if(readData == '\n'){	//Message ended.
            	message[position] = '\0';
            	printf("Message received!: %s \n\n", message);
            }else if(readData != '\r'){
            	message[position] = readData;
            	position++;
            }
        }
    }

}
