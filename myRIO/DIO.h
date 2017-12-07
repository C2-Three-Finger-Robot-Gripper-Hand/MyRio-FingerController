/*
 * DIO.h
 *
 * Copyright (c) 2013,
 * National Instruments Corporation.
 * All rights reserved.
 */

#ifndef DIO_h_
#define DIO_h_

#include "MyRio.h"

#if NiFpga_Cpp
extern "C" {
#endif


/**
 * Registers for a particular digital IO.
 */
typedef struct
{
    uint32_t reg;   /**< DIO register */
    uint8_t bit;    /**< Bit in the register to modify */
} MyRio_Dio;


/**
 * Write a voltage value to a single channel in the 8 channel bank.
 */
void Dio_WriteBit(MyRio_Dio* channel, NiFpga_Bool value);


/**
 * Read the value of a single channel in the 8 channel bank.
 */
NiFpga_Bool Dio_ReadBit(MyRio_Dio* channel);

#if NiFpga_Cpp
}
#endif

#endif /* DIO_h_ */
