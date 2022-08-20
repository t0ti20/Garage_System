/*File Guard*/
#ifndef _EXTERNAL_INTERRUPT_PRIVATE_H_
#define _EXTERNAL_INTERRUPT_PRIVATE_H_

/******** Registers ********/
#define   GIFR    *((volatile u8*)0x5A)
#define   GICR    *((volatile u8*)0x5B)
#define   MCUCR   *((volatile u8*)0x55)
#define   MCUCSR  *((volatile u8*)0x54)

/******** MCUCR_Bits ********/
#define   MCUCR_ISC00      0
#define   MCUCR_ISC01      1
#define   MCUCR_ISC10      2
#define   MCUCR_ISC11      3

/******** MCUCSR_Bits ********/
#define   MCUCSR_ISC2      6

/******** GICR_Bits ********/
#define   GICR_Interrupt_0        6
#define   GICR_Interrupt_1        7
#define   GICR_Interrupt_2        5

/******** GIFR_Bits ********/
#define   GIFR_Interrupt_F_0       6
#define   GIFR_Interrupt_F_1       7
#define   GIFR_Interrupt_F_2       5

/************* Macros for Configure ************/
#define     Low_Level       0
#define     On_Change       1
#define     Falling_Edge    2
#define     Rising_Edge     3
#define     Enable     	    0
#define     Disable         1
#endif 
/*EXTERNAL_INTERRUPT_PRIVATE_H_*/
