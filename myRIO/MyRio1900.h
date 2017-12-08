/*
 * myRIO 1900 Target Header File
 *
 * Definitions for myRIO 1900
 * This file should be included from "MyRio.h", never directly
 *
 * Copyright (c) 2013,
 * National Instruments Corporation.
 * All rights reserved.
 */

#ifndef MyRio1900_h_
#define MyRio1900_h_

/* Guard against direct include */
#ifndef MyRio_h_
#    error "Include MyRio.h instead of MyRio1900.h"
#endif


/* Guard against including multiple myRIO target header files. */
#ifndef MyRioXXXX
#   define MyRioXXXX "MyRio1900.h"
#else
#    error "Attempt to include more that one MyRioXXXX.h file."
#endif


/*
 * Include NiFpga header files
 */
#include "NiFpga.h"
#include "NiFpga_FPGAMainDefault.h"


/*
 * Set the Bitfile and the Signtature
 */
#define MyRio_Bitfile	NiFpga_FPGAMainDefault_Bitfile
#define MyRio_Signature NiFpga_FPGAMainDefault_Signature


/*
 * Define the weight and offset constants of connector A&B&C
 */
#if !defined(AIA_0WGHT)
#define AIA_0WGHT  1220703
#endif

#if !defined(AIA_0OFST)
#define AIA_0OFST  0
#endif

#if !defined(AIA_0SIGN)
#define AIA_0SIGN  0
#endif

#if !defined(AIA_1WGHT)
#define AIA_1WGHT  1220703
#endif

#if !defined(AIA_1OFST)
#define AIA_1OFST  0
#endif

#if !defined(AIA_1SIGN)
#define AIA_1SIGN  0
#endif

#if !defined(AIA_2WGHT)
#define AIA_2WGHT  1220703
#endif

#if !defined(AIA_2OFST)
#define AIA_2OFST  0
#endif

#if !defined(AIA_2SIGN)
#define AIA_2SIGN  0
#endif

#if !defined(AIA_3WGHT)
#define AIA_3WGHT  1220703
#endif

#if !defined(AIA_3OFST)
#define AIA_3OFST  0
#endif

#if !defined(AIA_3SIGN)
#define AIA_3SIGN  0
#endif

#if !defined(AIB_0WGHT)
#define AIB_0WGHT  1220703
#endif

#if !defined(AIB_0OFST)
#define AIB_0OFST  0
#endif

#if !defined(AIB_0SIGN)
#define AIB_0SIGN  0
#endif

#if !defined(AIB_1WGHT)
#define AIB_1WGHT  1220703
#endif

#if !defined(AIB_1OFST)
#define AIB_1OFST  0
#endif

#if !defined(AIB_1SIGN)
#define AIB_1SIGN  0
#endif

#if !defined(AIB_2WGHT)
#define AIB_2WGHT  1220703
#endif

#if !defined(AIB_2OFST)
#define AIB_2OFST  0
#endif

#if !defined(AIB_2SIGN)
#define AIB_2SIGN  0
#endif

#if !defined(AIB_3WGHT)
#define AIB_3WGHT  1220703
#endif

#if !defined(AIB_3OFST)
#define AIB_3OFST  0
#endif

#if !defined(AIB_3SIGN)
#define AIB_3SIGN  0
#endif

#if !defined(AIC_0WGHT)
#define AIC_0WGHT  4882813
#endif

#if !defined(AIC_0OFST)
#define AIC_0OFST  0
#endif

#if !defined(AIC_0SIGN)
#define AIC_0SIGN  1
#endif

#if !defined(AIC_1WGHT)
#define AIC_1WGHT  4882813
#endif

#if !defined(AIC_1OFST)
#define AIC_1OFST  0
#endif

#if !defined(AIC_1SIGN)
#define AIC_1SIGN  1
#endif

#if !defined(AUDIOINLEFT_WGHT)
#define AUDIOINLEFT_WGHT  1220703
#endif

#if !defined(AUDIOINLEFT_OFST)
#define AUDIOINLEFT_OFST  0
#endif

#if !defined(AUDIOINLEFT_SIGN)
#define AUDIOINLEFT_SIGN  1
#endif

#if !defined(AUDIOINRIGHT_WGHT)
#define AUDIOINRIGHT_WGHT  1220703
#endif

#if !defined(AUDIOINRIGHT_OFST)
#define AUDIOINRIGHT_OFST  0
#endif

#if !defined(AUDIOINRIGHT_SIGN)
#define AUDIOINRIGHT_SIGN  1
#endif

#if !defined(AOA_0WGHT)
#define AOA_0WGHT  1220703
#endif

#if !defined(AOA_0OFST)
#define AOA_0OFST  0
#endif

#if !defined(AOA_0SIGN)
#define AOA_0SIGN  0
#endif

#if !defined(AOA_1WGHT)
#define AOA_1WGHT  1220703
#endif

#if !defined(AOA_1OFST)
#define AOA_1OFST  0
#endif

#if !defined(AOA_1SIGN)
#define AOA_1SIGN  0
#endif

#if !defined(AOB_0WGHT)
#define AOB_0WGHT  1220703
#endif

#if !defined(AOB_0OFST)
#define AOB_0OFST  0
#endif

#if !defined(AOB_0SIGN)
#define AOB_0SIGN  0
#endif

#if !defined(AOB_1WGHT)
#define AOB_1WGHT  1220703
#endif

#if !defined(AOB_1OFST)
#define AOB_1OFST  0
#endif

#if !defined(AOB_1SIGN)
#define AOB_1SIGN  0
#endif

#if !defined(AOC_0WGHT)
#define AOC_0WGHT  4882813
#endif

#if !defined(AOC_0OFST)
#define AOC_0OFST  0
#endif

#if !defined(AOC_0SIGN)
#define AOC_0SIGN  0
#endif

#if !defined(AOC_1WGHT)
#define AOC_1WGHT  4882813
#endif

#if !defined(AOC_1OFST)
#define AOC_1OFST  0
#endif

#if !defined(AOC_1SIGN)
#define AOC_1SIGN  0
#endif

#if !defined(AUDIOOUTLEFT_WGHT)
#define AUDIOOUTLEFT_WGHT  1220703
#endif

#if !defined(AUDIOOUTLEFT_OFST)
#define AUDIOOUTLEFT_OFST  0
#endif

#if !defined(AUDIOOUTLEFT_SIGN)
#define AUDIOOUTLEFT_SIGN  1
#endif

#if !defined(AUDIOOUTRIGHT_WGHT)
#define AUDIOOUTRIGHT_WGHT  1220703
#endif

#if !defined(AUDIOOUTRIGHT_OFST)
#define AUDIOOUTRIGHT_OFST  0
#endif

#if !defined(AUDIOOUTRIGHT_SIGN)
#define AUDIOOUTRIGHT_SIGN  1
#endif

/*
 * Define the accelerometer weight constant.
 */
#if !defined(ACCSCALEWGHT_CST)
#define ACCSCALEWGHT_CST  256
#endif

/*
 * Define the IRQ number range
 */
#if !defined(IRQNO_MAX)
#define IRQNO_MAX  8
#endif

#if !defined(IRQNO_MIN)
#define IRQNO_MIN  1
#endif


/**
 * Redefinition of the NiFpga Bool Indicator enum.
 * This is provided as a convenience to shorten the default enum names. The
 * NiFpga_ReadBool and NiFpga_WriteBool functions should be used to access these
 * items.
 */
typedef enum
{
    AOSYSSTAT = NiFpga_FPGAMainDefault_IndicatorBool_AOSYSSTAT,
    SYSAIRDY = NiFpga_FPGAMainDefault_IndicatorBool_SYSAIRDY,
    SYSRDY = NiFpga_FPGAMainDefault_IndicatorBool_SYSRDY,
} MyRio1900Fpga20_IndicatorBool;


/**
 * Redefinition of the NiFpga U8 Indicator enum.
 * This is provided as a convenience to shorten the default enum names. The
 * NiFpga_ReadU8 and NiFpga_WriteU8 functions should be used to access these
 * items.
 */
typedef enum
{
    DIBTN = NiFpga_FPGAMainDefault_IndicatorU8_DIBTN,
} MyRio1900Fpga20_IndicatorU8;


/**
 * Redefinition of the NiFpga U16 Indicator enum.
 * This is provided as a convenience to shorten the default enum names. The
 * NiFpga_ReadU16 and NiFpga_WriteU16 functions should be used to access these
 * items.
 */
typedef enum
{
    AIA_0VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIA_0VAL,
    AIA_1VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIA_1VAL,
    AIA_2VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIA_2VAL,
    AIA_3VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIA_3VAL,
    AIB_0VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIB_0VAL,
    AIB_1VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIB_1VAL,
    AIB_2VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIB_2VAL,
    AIB_3VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIB_3VAL,
    AIC_0VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIC_0VAL,
    AIC_1VAL = NiFpga_FPGAMainDefault_IndicatorU16_AIC_1VAL,
} MyRio1900Fpga20_IndicatorU16;


/**
 * Redefinition of the NiFpga Bool Control enum.
 * This is provided as a convenience to shorten the default enum names. The
 * NiFpga_ReadBool and NiFpga_WriteBool functions should be used to access these
 * items.
 */
typedef enum
{
    AOSYSGO = NiFpga_FPGAMainDefault_ControlBool_AOSYSGO,
} MyRio1900Fpga20_ControlBool;


/**
 * Redefinition of the NiFpga U16 Control enum.
 * This is provided as a convenience to shorten the default enum names. The
 * NiFpga_ReadU16 and NiFpga_WriteU16 functions should be used to access these
 * items.
 */
typedef enum
{
    AOA_0VAL = NiFpga_FPGAMainDefault_ControlU16_AOA_0VAL,
    AOA_1VAL = NiFpga_FPGAMainDefault_ControlU16_AOA_1VAL,
    AOB_0VAL = NiFpga_FPGAMainDefault_ControlU16_AOB_0VAL,
    AOB_1VAL = NiFpga_FPGAMainDefault_ControlU16_AOB_1VAL,
    AOC_0VAL = NiFpga_FPGAMainDefault_ControlU16_AOC_0VAL,
    AOC_1VAL = NiFpga_FPGAMainDefault_ControlU16_AOC_1VAL,
} MyRio1900Fpga20_ControlU16;

#endif /* MyRio1900_h_ */
