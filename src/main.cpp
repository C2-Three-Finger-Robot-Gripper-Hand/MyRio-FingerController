/*
 * Copyright (c) 2013,
 * National Instruments Corporation.
 * All rights reserved.
 */

#include <stdio.h>
#include <cstdlib>
#include "MyRio.h"
#include "FingerController.h"
#include "NiFpga_MyRio1900Fpga20.h"
#include <exception>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

static FingerController *fingerController;


void exiting(int s){
	delete fingerController;
    MyRio_Close();
    exit(s);
}

void exit(){
	exiting(0);
}


/**
 * Overview:
 * myRIO main function. This template contains basic code to open the myRIO
 * FPGA session. You can remove this code if you only need to use the UART.
 *
 * Code in myRIO example projects is designed for reuse. You can copy source
 * files from the example project to use in this template.
 *
 * Note:
 * The Eclipse project defines the preprocessor symbol for the NI myRIO-1900.
 * Change the preprocessor symbol to use this example with the NI myRIO-1950.
 */
int main(int argc, char **argv)
{
    NiFpga_Status status;

    /*
     * Open the myRIO NiFpga Session.
     * This function MUST be called before all other functions. After this call
     * is complete the myRIO target will be ready to be used.
     */
    status = MyRio_Open();
    if (MyRio_IsNotSuccess(status))
    {
        return status;
    }

    //Add closing function on exit
    struct sigaction sigIntHandler;

    sigIntHandler.sa_handler = exiting;
    sigemptyset(&sigIntHandler.sa_mask);
    sigIntHandler.sa_flags = 0;

    sigaction(SIGINT, &sigIntHandler, NULL);

    std::atexit(exit);
    std::set_terminate(exit);

    /*
     * Your application code goes here.
     */
    fingerController = new FingerController();

    fingerController->run();

    /*
     * Close the myRIO NiFpga Session.
     * This function MUST be called after all other functions.
     */

    return 1;
}


