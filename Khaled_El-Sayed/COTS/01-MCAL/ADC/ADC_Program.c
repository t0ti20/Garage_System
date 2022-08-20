/*------------------------------- INCLUDE -------------------------------*/
#include  "../../04-Library/Bit_Math.h"
#include  "../../04-Library/Standard_Types.h"
#include  "ADC_Private.h"
#include  "ADC_Config.h"
#include  "ADC_Interface.h"


/*------------------------- OPTIONS FOR ADC -------------------------*/

void ADC_VidInitialization ()
{
	/*SELECT REFERANCE*/
	#if Voltage_Referace == Internal
		Clear_Bit(ADMUX, ADMUX_REFS0);
		Clear_Bit(ADMUX, ADMUX_REFS1);
	#elif Voltage_Referace == AREF
		Set_Bit(ADMUX, ADMUX_REFS0);
		Clear_Bit(ADMUX, ADMUX_REFS1);
	#elif Voltage_Referace == Internal_2.56
		Clear_Bit(ADMUX, ADMUX_REFS0);
		Set_Bit(ADMUX, ADMUX_REFS1);
	#else
			#warning (" Wrong Configuration !!")
	#endif

		/*ACTIVE ADJUST*/
	Set_Bit(ADMUX, ADMUX_ADLAR);

		/*SELECT PRESCALAR*/
	#if ADC_Prescaler == Prescaler_2
		Clear_Bit(ADCSRA,ADCSRA_ADPS0);
		Clear_Bit(ADCSRA,ADCSRA_ADPS1);
		Clear_Bit(ADCSRA,ADCSRA_ADPS2);
	#elif ADC_Prescaler == Prescaler_4
		Clear_Bit(ADCSRA,ADCSRA_ADPS0);
		Set_Bit(ADCSRA,ADCSRA_ADPS1);
		Clear_Bit(ADCSRA,ADCSRA_ADPS2);
	#elif ADC_Prescaler == Prescaler_8
		Set_Bit(ADCSRA,ADCSRA_ADPS0);
		Set_Bit(ADCSRA,ADCSRA_ADPS1);
		Clear_Bit(ADCSRA,ADCSRA_ADPS2);
	#elif ADC_Prescaler == Prescaler_16
		Clear_Bit(ADCSRA,ADCSRA_ADPS0);
		Clear_Bit(ADCSRA,ADCSRA_ADPS1);
		Set_Bit(ADCSRA,ADCSRA_ADPS2);
	#elif ADC_Prescaler == Prescaler_32
		Set_Bit(ADCSRA,ADCSRA_ADPS0);
		Clear_Bit(ADCSRA,ADCSRA_ADPS1);
		Set_Bit(ADCSRA,ADCSRA_ADPS2);
	#elif ADC_Prescaler == Prescaler_128
		Set_Bit(ADCSRA,ADCSRA_ADPS0);
		Set_Bit(ADCSRA,ADCSRA_ADPS1);
		Set_Bit(ADCSRA,ADCSRA_ADPS2);
	#else
		#warning (" Wrong Configuration !! ")
	#endif

		/*ENABLE*/
	Set_Bit(ADCSRA,ADCSRA_ADEN);
}


/*------------------------- Sync_Reading -------------------------*/

void ADC_VidSync_Reading (u8 Copy_u8Channel,u8 *Copy_u8Reading)
{
	ADMUX &= 0xE0;
	ADMUX = ADMUX | Copy_u8Channel;
	Set_Bit(ADCSRA,ADCSRA_ADSC);			/* Start Conversion */
	while(!Get_Bit(ADCSRA,ADCSRA_ADIF));
	Set_Bit(ADCSRA,ADCSRA_ADIF);
	*Copy_u8Reading=ADCH;
}


/*------------------------- ASync Reading -------------------------*/

void ADC_VidAsync_Reading (u8 Copy_u8Channel,u8 *Copy_u8Reading)
{
	ADMUX &= 0xE0;
	ADMUX = ADMUX | Copy_u8Channel;
	Set_Bit(ADCSRA,ADCSRA_ADSC);			/* Start Conversion */
	while(!Get_Bit(ADCSRA,ADCSRA_ADIF));
	Set_Bit(ADCSRA,ADCSRA_ADIF);
	*Copy_u8Reading=ADCH;
}


/*------------------------- Mapped Reading -------------------------*/

void ADC_VidAsync_Mapped_Reading (u8 Copy_u8Channel,u32 Copy_u8Min,u32 Copy_u8Max,u32 * Copy_u32Reading)
{
	ADMUX &= 0xE0;
	ADMUX = ADMUX | Copy_u8Channel;
	Set_Bit(ADCSRA,ADCSRA_ADSC);			/* Start Conversion */
	while(!Get_Bit(ADCSRA,ADCSRA_ADIF));
	Set_Bit(ADCSRA,ADCSRA_ADIF);
	* Copy_u32Reading=((((ADCH)*(Copy_u8Max-Copy_u8Min))/(255UL))+Copy_u8Min);
}
