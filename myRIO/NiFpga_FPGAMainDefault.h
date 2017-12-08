/*
 * Generated with the FPGA Interface C API Generator 15.0.0
 * for NI-RIO 15.0.0 or later.
 */

#ifndef __NiFpga_FPGAMainDefault_h__
#define __NiFpga_FPGAMainDefault_h__

#ifndef NiFpga_Version
   #define NiFpga_Version 1500
#endif

#include "NiFpga.h"

/**
 * The filename of the FPGA bitfile.
 *
 * This is a #define to allow for string literal concatenation. For example:
 *
 *    static const char* const Bitfile = "C:\\" NiFpga_FPGAMainDefault_Bitfile;
 */
#define NiFpga_FPGAMainDefault_Bitfile "/home/admin/gripperhand/fingercontroller/NiFpga_FPGAMainDefault.lvbitx"

/**
 * The signature of the FPGA bitfile.
 */
static const char* const NiFpga_FPGAMainDefault_Signature = "5372684EB6B3C8C76694174618D9C8F6";

typedef enum
{
   NiFpga_FPGAMainDefault_IndicatorBool_AOSYSSTAT = 0x1804A,
   NiFpga_FPGAMainDefault_IndicatorBool_SYSAIRDY = 0x1802A,
   NiFpga_FPGAMainDefault_IndicatorBool_SYSRDY = 0x18026,
} NiFpga_FPGAMainDefault_IndicatorBool;

typedef enum
{
   NiFpga_FPGAMainDefault_IndicatorU8_DIBTN = 0x18006,
   NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN1 = 0x1801E,
   NiFpga_FPGAMainDefault_IndicatorU8_DIOB_30IN2 = 0x1800A,
   NiFpga_FPGAMainDefault_IndicatorU8_ENC1STAT = 0x1802E,
   NiFpga_FPGAMainDefault_IndicatorU8_ENC2STAT = 0x1803A,
   NiFpga_FPGAMainDefault_IndicatorU8_ENC3STAT = 0x1800E,
} NiFpga_FPGAMainDefault_IndicatorU8;

typedef enum
{
   NiFpga_FPGAMainDefault_IndicatorU16_AIA_0VAL = 0x1808A,
   NiFpga_FPGAMainDefault_IndicatorU16_AIA_1VAL = 0x18086,
   NiFpga_FPGAMainDefault_IndicatorU16_AIA_2VAL = 0x18082,
   NiFpga_FPGAMainDefault_IndicatorU16_AIA_3VAL = 0x1807E,
   NiFpga_FPGAMainDefault_IndicatorU16_AIB_0VAL = 0x1807A,
   NiFpga_FPGAMainDefault_IndicatorU16_AIB_1VAL = 0x18076,
   NiFpga_FPGAMainDefault_IndicatorU16_AIB_2VAL = 0x18072,
   NiFpga_FPGAMainDefault_IndicatorU16_AIB_3VAL = 0x1806E,
   NiFpga_FPGAMainDefault_IndicatorU16_AIC_0VAL = 0x1806A,
   NiFpga_FPGAMainDefault_IndicatorU16_AIC_1VAL = 0x18066,
} NiFpga_FPGAMainDefault_IndicatorU16;

typedef enum
{
   NiFpga_FPGAMainDefault_IndicatorU32_ENC1CNTR = 0x18030,
   NiFpga_FPGAMainDefault_IndicatorU32_ENC2CNTR = 0x1803C,
   NiFpga_FPGAMainDefault_IndicatorU32_ENC3CNTR = 0x18010,
} NiFpga_FPGAMainDefault_IndicatorU32;

typedef enum
{
   NiFpga_FPGAMainDefault_ControlBool_AOSYSGO = 0x1804E,
} NiFpga_FPGAMainDefault_ControlBool;

typedef enum
{
   NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT1 = 0x18022,
   NiFpga_FPGAMainDefault_ControlU8_DIOB_30OUT2 = 0x1801A,
   NiFpga_FPGAMainDefault_ControlU8_DOLED30 = 0x18046,
   NiFpga_FPGAMainDefault_ControlU8_ENC1CNFG = 0x18036,
   NiFpga_FPGAMainDefault_ControlU8_ENC2CNFG = 0x18042,
   NiFpga_FPGAMainDefault_ControlU8_ENC3CNFG = 0x18016,
} NiFpga_FPGAMainDefault_ControlU8;

typedef enum
{
   NiFpga_FPGAMainDefault_ControlU16_AOA_0VAL = 0x18002,
   NiFpga_FPGAMainDefault_ControlU16_AOA_1VAL = 0x18062,
   NiFpga_FPGAMainDefault_ControlU16_AOB_0VAL = 0x1805E,
   NiFpga_FPGAMainDefault_ControlU16_AOB_1VAL = 0x1805A,
   NiFpga_FPGAMainDefault_ControlU16_AOC_0VAL = 0x18056,
   NiFpga_FPGAMainDefault_ControlU16_AOC_1VAL = 0x18052,
} NiFpga_FPGAMainDefault_ControlU16;

#endif
