/****************************

  HSSD_Program.c
  Author : Zeyad Mahmoud
  Version : v1
  Date : 28 October 2022

*****************************/


/* Service Layer */
#include "../Service_Layer/BIT_CALC.h"
#include "../Service_Layer/STD_TYPES.h"


/* MCAL Layer */
#include "../DIO_Driver/DIO_config.h"
#include "../DIO_Driver/DIO_interface.h"
#include "../DIO_Driver/DIO_private.h"


/*Hal Layer*/
#include "HSSD_Config.h"
#include "HSSD_interface.h"
#include "HSSD_Private.h"


/**
Function Name : HSSD_vidInit
Function Return : void
Function Arguments : u8 Copy_u8Port
Function Description : Initialize the 7-Segment
**/

void HSSD_vidInit(u8 Copy_u8Port){
  /* initialize the port as output*/
  DIO_u8SetPortDirection(Copy_u8Port,OUTPUTPORT);
}


/**
Function Name : HSSD_vidSetNumber
Function Return : void
Function Arguments : u8 Copy_u8Port
Function Description : set the 7-segment displaying number
**/

void HSSD_vidSetNumber(u8 Copy_u8Port, u8 Copy_u8Number){
  DIO_u8SetPortValue(Copy_u8Port, Copy_u8Number);
}
