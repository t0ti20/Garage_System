/*File Guard*/
#ifndef _ADC_CONFIG_PRIVATE_H_
#define _ADC_CONFIG_PRIVATE_H_

/************* Macros for Configure ************/

#define     Internal            0     /*AREF, Internal VREF turned off*/
#define     AREF                1     /*AVCC with external capacitor at AREF pin*/
#define 	Internal_2_5		3     /*Internal 2.56V Voltage Reference with external capacitor at AREF pin*/
#define     Prescaler_2			0     /*Prescaler (2)*/
#define     Prescaler_4			1	  /*Prescaler (4)*/
#define     Prescaler_8			2	  /*Prescaler (8)*/
#define     Prescaler_16		3	  /*Prescaler (16)*/
#define     Prescaler_32		4	  /*Prescaler (32)*/
#define     Prescaler_64		5	  /*Prescaler (64)*/
#define     Prescaler_128		6	  /*Prescaler (128)*/

/******** Registers ********/
#define   ADMUX     *((volatile u8*)0x27)
#define   ADCSRA    *((volatile u8*)0x26)
#define   ADCH      *((volatile u8*)0x25)
#define   ADCL      *((volatile u8*)0x24)
#define   SFIOR     *((volatile u8*)0x50)
#define   ADCSR     *((volatile u8*)0x5B)


/******** ADMUX_Bits ********/       
#define   ADMUX_REFS1               7
#define   ADMUX_REFS0               6
#define   ADMUX_ADLAR               5
#define   ADMUX_MUX_0				0
#define   ADMUX_MUX_1				1
#define   ADMUX_MUX_2				2
#define   ADMUX_MUX_3				3
#define   ADMUX_MUX_4				4

/******** ADCSRA_Bits ********/
#define   ADCSRA_ADEN               7
#define   ADCSRA_ADSC               6
#define   ADCSRA_ADATE              5
#define   ADCSRA_ADIF               4
#define   ADCSRA_ADIE               3
#define   ADCSRA_ADPS2              2
#define   ADCSRA_ADPS1              1
#define   ADCSRA_ADPS0              0

/******** SFIOR_Bits ********/
#define   SFIOR_ADTS2         7
#define   SFIOR_ADTS1         6
#define   SFIOR_ADTS0         5

/******** GIFR_Bits ********/
#define   GIFR_Interrupt_F_0       6
#define   GIFR_Interrupt_F_1       7
#define   GIFR_Interrupt_F_2       5

#endif 
/*_ADC_CONFIG_PRIVATE_H_*/
