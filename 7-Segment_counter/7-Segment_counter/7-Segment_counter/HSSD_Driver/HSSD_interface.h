/*************************************
  HSSD_Interface.h
  Author: Zeyad Mahmoud
  Version: v1
  Date: 28 october 2022
**************************************/

#ifndef HSSD_INTERFACE_H_
#define HSSD_INTERFACE_H_


/* Service layer */
#include "../Service_Layer/BIT_CALC.h"
#include "../Service_Layer/STD_TYPES.h"

/* MCAL Layer */
#include "../Dio_Driver/DIO_config.h"
#include "../Dio_Driver/DIO_interface.h"
#include "../Dio_Driver/DIO_private.h"

/* Hal Layer*/
#include "HSSD_Config.h"

/* 7-segment initialization */
void HSSD_vidInit(u8 Copy_u8Port);

/* 7-segment set number to display */
void HSSD_vidSetNumber(u8 copy_u8Port, u8 Copy_u8Number);

#endif // HSSD_INTERFACE_H_
