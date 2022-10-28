
/* Service layer */
#include "../Service_Layer/STD_TYPES.h"
#include "../Service_Layer/BIT_CALC.h"

/* MCAL layer */
#include "DIO_interface.h"
#include "DIO_config.h"
#include "DIO_private.h"


enum MSG{PORT_ERROR, DIRECTION_ERROR, PIN_ERROR}; /* to handle errors as message */


/**
  Function Name        :  DIO_SetPinDirection
  Function Return      :  u8
  Function Argument    :  u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction
  Function description :  Initialize the pin as input or output
 **/
extern u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction){

  u8 local_u8Flag = 0; /* initialized as not ok*/
  if(Copy_u8Port > 3 && Copy_u8Port < 0) local_u8Flag = PORT_ERROR; /* MSG : Port is not OK */
  if(Copy_u8Pin > 7 && Copy_u8Pin < 0) local_u8Flag = PIN_ERROR; /* MSG : pin not OK */
  if(Copy_u8Direction != 0 && Copy_u8Direction != 1) local_u8Flag = DIRECTION_ERROR; /* MSG Direction not OK*/

  if(local_u8Flag == 0){
      local_u8Flag = 1;
      switch(Copy_u8Port){
      case PORT_A:
          if(Copy_u8Direction == OUTPUTPIN){
            /* set the direction of the given pin as output*/
            SETBIT(DDRA,Copy_u8Pin);
          }
          else if(Copy_u8Direction == INPUTPIN){
            /* set the direction of the given pin as input */
            CLEARBIT(DDRA,Copy_u8Pin);
          }
          break;
        case PORT_B:
          if(Copy_u8Direction == OUTPUTPIN){
            /* set the direction of the given pin as output*/
            SETBIT(DDRB,Copy_u8Pin);
          }
          else if(Copy_u8Direction == INPUTPIN){
            /* set the direction of the given pin as input */
            CLEARBIT(DDRB,Copy_u8Pin);
          }
          break;
        case PORT_C:
          if(Copy_u8Direction == OUTPUTPIN){
            /* set the direction of the given pin as output*/
            SETBIT(DDRC,Copy_u8Pin);
          }
          else if(Copy_u8Direction == INPUTPIN){
            /* set the direction of the given pin as input */
            CLEARBIT(DDRC,Copy_u8Pin);
          }
          break;
        case PORT_D:
          if(Copy_u8Direction == OUTPUTPIN){
            /* set the direction of the given pin as output*/
            SETBIT(DDRD,Copy_u8Pin);
          }
          else if(Copy_u8Direction == INPUTPIN){
            /* set the direction of the given pin as input */
            CLEARBIT(DDRD,Copy_u8Pin);
          }
          break;
      }
  }

  return local_u8Flag;
}

/**
  Function Name        :  DIO_u8SetPinValue
  Function Return      :  u8
  Function Argument    :  u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value
  Function description :  Initialize the pin value to high or low
 **/

extern u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value){
  u8 local_u8Flag = 0; /* initialized as not ok*/
  if(Copy_u8Port > 3 && Copy_u8Port < 0) local_u8Flag = PORT_ERROR; /* MSG : Port is not OK */
  if(Copy_u8Pin > 7 && Copy_u8Pin < 0) local_u8Flag = PIN_ERROR; /* MSG : pin not OK */

  if(local_u8Flag == 0){
      local_u8Flag = 1;
      switch(Copy_u8Port){

      case PORT_A:
        if(Copy_u8Value == HIGH){
          /* set the Value of the given pin as HIGH*/
          SETBIT(PORTA,Copy_u8Pin);
        }
        else if(Copy_u8Value == LOW){
          /* set the Value of the given pin as LOW */
          CLEARBIT(PORTA,Copy_u8Pin);
        }
        break;
        case PORT_B:
          if(Copy_u8Value == HIGH){
            /* set the Value of the given pin as HIGH*/
            SETBIT(PORTB,Copy_u8Pin);
          }
          else if(Copy_u8Value == LOW){
            /* set the Value of the given pin as LOW */
            CLEARBIT(PORTB,Copy_u8Pin);
          }
          break;
        case PORT_C:
          if(Copy_u8Value == HIGH){
            /* set the Value of the given pin as HIGH*/
            SETBIT(PORTC,Copy_u8Pin);
          }
          else if(Copy_u8Value == LOW){
            /* set the Value of the given pin as LOW */
            CLEARBIT(PORTC,Copy_u8Pin);
          }
          break;
        case PORT_D:
          if(Copy_u8Value == HIGH){
            /* set the Value of the given pin as HIGH*/
            SETBIT(PORTD,Copy_u8Pin);
          }
          else if(Copy_u8Value == LOW){
            /* set the Value of the given pin as LOW */
            CLEARBIT(PORTD,Copy_u8Pin);
          }
          break;
      }
  }

  return local_u8Flag;
}


/**
  Function Name        :  DIO_u8GetPinValue
  Function Return      :  u8
  Function Argument    :  u8 Copy_u8Port, u8 Copy_u8Pin
  Function description :  get the value of the given pin
 **/

extern u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin){
  u8 local_u8Flag = 0; /* initialized as not OK*/
  if(Copy_u8Port > 3 && Copy_u8Port < 0) local_u8Flag = PORT_ERROR; /* MSG : Port is not OK */
  if(Copy_u8Pin > 7 && Copy_u8Pin < 0) local_u8Flag = PIN_ERROR; /* MSG : pin not OK */

  if(local_u8Flag == 0){
      local_u8Flag = 1;
    switch(Copy_u8Port){
      case PORT_A:
          /* read the value from the given bin */
          return GETBIT(PINA,Copy_u8Pin);
          break;
      case PORT_B:
          /* read the value from the given bin */
          return GETBIT(PINB,Copy_u8Pin);
          break;
      case PORT_C:
          /* read the value from the given bin */
          return GETBIT(PINC,Copy_u8Pin);
          break;
      case PORT_D:
          /* read the value from the given bin */
          return GETBIT(PIND,Copy_u8Pin);
          break;
    }
  }
  return local_u8Flag;
}


/**
  Function Name        :  DIO_u8SetPortDirection
  Function Return      :  u8
  Function Argument    :  u8 Copy_u8Port, u8 u8Copy_u8PortDirectionu8Copy_u8PortDirection
  Function description :  Initialize the port direction  as input or output
 **/

 extern u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8PortDirection){
  u8 local_u8Flag = 0; /* initialized as not ok*/
  if(Copy_u8Port > 3 && Copy_u8Port < 0) local_u8Flag = PORT_ERROR; /* MSG : Port is not OK */
  if(Copy_u8PortDirection != OUTPUTPORT && Copy_u8PortDirection != INPUTPORT) local_u8Flag = DIRECTION_ERROR; /* MSG Direction not OK*/

  if(local_u8Flag == 0){
      local_u8Flag = 1;
      switch(Copy_u8Port){
      case PORT_A:
          DDRA = Copy_u8PortDirection;
          break;
        case PORT_B:
          DDRB = Copy_u8PortDirection;
          break;
        case PORT_C:
          DDRC = Copy_u8PortDirection;
          break;
        case PORT_D:
          DDRD = Copy_u8PortDirection;
          break;
      }
  }
  return local_u8Flag;
 }


/**
  Function Name        :  DIO_u8SetPortValue
  Function Return      :  u8
  Function Argument    :  u8 Copy_u8Port, u8 Copy_u8PortValue
  Function description :  Initialize the port valus as high or low
 **/

extern u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8PortValue){
  u8 local_u8Flag = 0; /* initialized as not ok*/
  if(Copy_u8Port > 3 && Copy_u8Port < 0) local_u8Flag = PORT_ERROR; /* MSG : Port is not OK */

  if(local_u8Flag == 0){
    local_u8Flag = 1;
    switch(Copy_u8Port){
      case PORT_A:
        PORTA = Copy_u8PortValue;
        break;
        case PORT_B:
          PORTB = Copy_u8PortValue;
        case PORT_C:
          PORTC = Copy_u8PortValue;
          break;
        case PORT_D:
          PORTD = Copy_u8PortValue;
          break;
      }
  }

  return local_u8Flag;
}

/**
  Function Name        :  Dio_u8TogglePinVlaue
  Function Return      :  u8
  Function Argument    :  u8 Copy_u8Port, u8 Copy_u8Pin
  Function description :  toggle the value of the given pin
 **/

extern u8 Dio_u8TogglePinVlaue(u8 Copy_u8Port, u8 Copy_u8Pin){
  u8 local_u8Flag = 0; /* initialized as not ok*/
  if(Copy_u8Port > 3 && Copy_u8Port < 0) local_u8Flag = PORT_ERROR; /* MSG : Port is not OK */
  if(Copy_u8Pin > 7 && Copy_u8Pin < 0) local_u8Flag = PIN_ERROR; /* MSG : pin not OK */

  if(local_u8Flag = 0){
    switch(Copy_u8Port){
      case PORT_A:
        TOGGLEBIT(PORTA,Copy_u8Pin);
        break;
      case PORT_B:
        TOGGLEBIT(PORTB,Copy_u8Pin);
        break;
      case PORT_C:
        TOGGLEBIT(PORTC,Copy_u8Pin);
        break;
      case PORT_D:
        TOGGLEBIT(PORTD,Copy_u8Pin);
        break;
    }
  }
  return local_u8Flag;
}
