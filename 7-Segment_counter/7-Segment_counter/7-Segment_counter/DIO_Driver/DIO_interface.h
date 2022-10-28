/*************************************
  DIO_INTERFACE.h
  Author: Zeyad Mahmoud
  Version: v1
  Date: 24 october 2022
**************************************/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#include "../Service_Layer/STD_TYPES.h"

/** pins config **/
#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7


/** ports config **/
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3


/** direction & value config **/
#define HIGH 1
#define LOW 0
#define HIGHPORT 0xFF
#define LOWPORT 0x00


#define OUTPUTPIN 1
#define INPUTPIN 0
#define OUTPUTPORT 0xFF
#define INPUTPORT 0x00

/** DIO registers **/

/* PORTA*/
#define DDRA  *((volatile u8 *)0x3A)
#define PORTA *((volatile u8 *)0x3B)
#define PINA  *((volatile u8 *)0x39)

/* PORTB*/
#define DDRB  *((volatile u8 *)0x37)
#define PORTB *((volatile u8 *)0x38)
#define PINB  *((volatile u8 *)0x36)

/* PORTC*/
#define DDRC  *((volatile u8 *)0x34)
#define PORTC *((volatile u8 *)0x35)
#define PINC  *((volatile u8 *)0x33)

/* PORTD*/
#define DDRD  *((volatile u8 *)0x31)
#define PORTD *((volatile u8 *)0x32)
#define PIND  *((volatile u8 *)0x30)



/** To set the pin direction **/
extern u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/** To set the Pin value **/
extern u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

/** To get the pin value **/
extern u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin);

/** To set the port direction **/
extern u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDirection);

/** To set Port Value **/
extern u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue);

/** to change pin value from 1 to 0 or from 0 to 1 **/
extern u8 Dio_u8TogglePinVlaue(u8 Copy_u8Port, u8 Copy_u8Pin);


#endif // DIO_INTERFACE_H_
