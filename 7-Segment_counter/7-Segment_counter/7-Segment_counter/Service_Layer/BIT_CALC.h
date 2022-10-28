/*************************************
  BIT_CALC.h
  Author: Zeyad Mahmoud
  Version: v1
  Date: 24 october 2022
**************************************/


#ifndef BIT_CALC_H_H
#define BIT_CALC_H_H

#define SETBIT(val,bit) val |= (1<<bit)
#define TOGGLEBIT(val,bit) val ^=(1<<bit)
#define CLEARBIT(val,bit)  val &= ~(1<<bit)
#define GETBIT(val,bit)  (1&(val>>bit))

#endif // BIT_CALC_H_H
