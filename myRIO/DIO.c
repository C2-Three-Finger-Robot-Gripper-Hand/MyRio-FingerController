/*
 * Example for performing Basic Digital Input and Output
 *
 * Copyright (c) 2013,
 * National Instruments Corporation.
 * All rights reserved.
 */

#include <stdio.h>

/*
 * Include the myRIO header file.
 * The target type must be defined in your project, as a stand-alone #define,
 * or when calling the compiler from the command-line.
 */
#include "MyRio.h"
#include "DIO.h"


/*
 * Declare the myRIO NiFpga_Session so that it can be used by any function in
 * this file. The variable is actually defined in myRIO.c.
 *
 * This removes the need to pass the myrio_session around to every function and
 * only has to be declared when it is being used.
 */
extern NiFpga_Session myrio_session;


/**
 * Write a voltage value to a single channel in the 8 channel bank.
 *
 * The DIO channels are accessed in 8-bit banks where each bit in the bank
 * corresponds to one of the DIO channels. In general:
 *    DIO0 = bit0   (1st channel on the DIO 7:0 bank)
 *    DIO1 = bit1   (2nd channel on the DIO 7:0 bank)
 *       ...
 *    DIO7 = bit7   (last channel on the DIO 7:0 bank)
 *    DIO8 = bit0   (1st channel on the DIO 15:8 bank)
 *      ...
 *    DIO15 - bit7  (last channel on the DIO 15:8 bank)
 *
 * A DIO channel can be either an input or an output depending on the value
 * of the DIR register. A value of 0 makes the channel an input, a value of 1
 * sets the channel as an output.
 *
 * The hardware will drive the voltage level at the DIO channel pin based on
 * the value of the OUT register. A value of 0 will drive a low voltage (0
 * volts), a value of 1 will drive a high voltage (3.3 volts).
 *
 * @param[in]  channel  A struct containing the registers and bit location for
 *                      the DIO channel to be written to
 * @param[in]  value    The logical value of the voltage to be written
 */
void Dio_WriteBit(MyRio_Dio* channel, NiFpga_Bool value)
{
    NiFpga_Status status;
//    uint8_t dirValue;
    uint8_t outValue;

    /*
     * Get the value of the output register.
     *
     * The returned NiFpga_Status value is stored for error checking.
     */
    status = NiFpga_ReadU8(myrio_session, channel->reg, &outValue);


    /*
     * Clear the value of the appropriate bit in the output register. This is
     * done so that the correct value can be set later on.
     */
    outValue = outValue & ~(1 << channel->bit);

    /*
     * Set the value of the appropriate bit in the output register. If the
     * value to set is 0 this operation would not work unless the bit was
     * previously cleared.
     */
    outValue = outValue | (value << channel->bit);

    /*
     * Write the new value of the output register to the device.
     */
    NiFpga_MergeStatus(&status,
            NiFpga_WriteU8(myrio_session, channel->reg, outValue));


    /*
     * Check if there was an error writing to DIO channel registers.
     *
     * If there was an error then print an error message to stdout.
     */
    MyRio_ReturnIfNotSuccess(status,
            "Could not write to the DIO channel registers!")
}


/**
 * Read the value of a single channel in the 8 channel bank.
 *
 * The DIO channels are accessed in 8-bit banks where each bit in the bank
 * corresponds to one of the DIO channels. In general:
 *    DIO0 = bit0   (1st channel on the DIO 7:0 bank)
 *    DIO1 = bit1   (2nd channel on the DIO 7:0 bank)
 *       ...
 *    DIO7 = bit7   (last channel on the DIO 7:0 bank)
 *    DIO8 = bit0   (1st channel on the DIO 15:8 bank)
 *      ...
 *    DIO15 - bit7  (last channel on the DIO 15:8 bank)
 *
 * A DIO channel can be either an input or an output depending on the value
 * of the DIR register. A value of 0 makes the channel an input, a value of 1
 * sets the channel as an output.
 *
 * The voltage level present at the DIO channel pin can be determined based on
 * the value of the IN register. A value of 0 means a low voltage (0 volts) is
 * present, a value of 1 means a high voltage (3.3 volts) is present.
 *
 * @param[in]  channel  A struct containing the registers and bit location for
 *                      the DIO channel to be read from
 * @return NiFpga_Bool which is the logical value of the voltage on the channel
 */
NiFpga_Bool Dio_ReadBit(MyRio_Dio* channel)
{
    NiFpga_Status status;
//    uint8_t dirValue;
    uint8_t inValue;
//    uint8_t dirMask;

    /*
     * Get the value of the input register.
     *
     * NiFpga_MergeStatus is used to propagate any errors from previous
     * function calls. Errors are not anticipated so error checking is not done
     * after every NiFpga function call but only at specific points.
     */
    status = NiFpga_ReadU8(myrio_session, channel->reg, &inValue);

    /*
     * Check if there was an error writing to or reading from the DIO channel
     * registers.
     *
     * If there was an error then the rest of the function cannot complete
     * correctly so print an error message to stdout and return from the
     * function early.
     */
    MyRio_ReturnValueIfNotSuccess(status, NiFpga_False,
        "Could not write to/read from the DIO channel direction/in register!")

    /*
     * Isolate the value of the relevant bit.
     */
    inValue = inValue & (1 << channel->bit);

    /*
     *  If inValue > 0 then return NiFpga_True otherwise return NiFpga_False.
     */
    return (inValue > 0) ? NiFpga_True : NiFpga_False;
}
