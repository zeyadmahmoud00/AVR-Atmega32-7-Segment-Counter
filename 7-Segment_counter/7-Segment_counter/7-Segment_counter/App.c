/*
 * App.c
 *
 * Created: 10/28/2022 5:36:10 PM
 *  Author: Zeyad Mahmoud
 */ 

/*Service Layer*/
#include "Service_Layer/BIT_CALC.h"
#include "Service_Layer/STD_TYPES.h"

/* MCAL Layer */
#include "DIO_Driver/DIO_config.h"
#include "DIO_Driver/DIO_interface.h"
#include "DIO_Driver/DIO_private.h"

/* HAL Layer */
#include "HSSD_Driver/HSSD_Config.h"
#include "HSSD_Driver/HSSD_interface.h"
#include "HSSD_Driver/HSSD_Private.h"

#include <xc.h>
#include <avr/delay.h>


int main(void)
{
	u8 Local_arrSevenSegmentNumber[10] = {0b00111111,0b0000110,0b1011011,0b1001111,0b1100110,
										   0b1101101,0b1111101,0b0000111,0b11111111,0b1101111};
	HSSD_vidInit(PORT_A);
    while(1)
    {
        for (u8 i = 0; i < 10; ++i){
			HSSD_vidSetNumber(PORT_A, Local_arrSevenSegmentNumber[i]);
			_delay_ms(1000);
		}
    }
}