/*-----------------------------------------------------------------------*/
/*------------------------------- INCLUDE -------------------------------*/
/*-----------------------------------------------------------------------*/
#include  "../../04-Library/Bit_Math.h"
#include  "../../04-Library/Standard_Types.h"
#include  "Timer_Config.h"
#include  "Timer_Private.h"
#include  "Timer_Interface.h"


/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------- Main Fuctions --------------------------------------------------------------------------*/
/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/************************************************/
/*					Timer 0 					*/
/************************************************/
	void Timer_0_VidInitialization (u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Pre_Scalar)
	{
		switch(Copy_u8Mode)
		{
			case(Normal):Clear_Bit(TCCR0 , TCCR0_WGM00);Clear_Bit(TCCR0 , TCCR0_WGM01);OCR0=Copy_u8OCR_Value;break;
			case(CTC):Clear_Bit(TCCR0 , TCCR0_WGM00);Set_Bit(TCCR0 , TCCR0_WGM01);OCR0=Copy_u8OCR_Value;break;
			case(PWM_Phase_Correct):Set_Bit(TCCR0 , TCCR0_WGM00);Clear_Bit(TCCR0 , TCCR0_WGM01);break;
			case(Fast_PWM):Set_Bit(TCCR0 , TCCR0_WGM00);Set_Bit(TCCR0 , TCCR0_WGM01);break;
			default :Clear_Bit(TCCR0 , TCCR0_WGM00);Clear_Bit(TCCR0 , TCCR0_WGM01);
		}
		switch(Copy_u8Over_Flow_Interrupt)
		{
			case(Enable_OF):Set_Bit(TIMSK , TIMSK_TOIE0);break;
			case(Disable_OF):Clear_Bit(TIMSK , TIMSK_TOIE0);break;
			default:Set_Bit(TIMSK , TIMSK_TOIE0);
		}
		switch(Copy_u8Compare_Match_Interrupt)
		{
			case(Enable_CM):Set_Bit(TIMSK , TIMSK_OCIE0);break;
			case(Disable_CM):Clear_Bit(TIMSK , TIMSK_OCIE0);break;
			default:Set_Bit(TIMSK , TIMSK_OCIE0);
		}
		if((Copy_u8Mode==PWM_Phase_Correct)||(Copy_u8Mode==Fast_PWM))
		{
			#if	PWM_Mode == COCSOB
				Clear_Bit(TCCR0 , TCCR0_COM00);
				Set_Bit(TCCR0 , TCCR0_COM01);
			#elif PWM_Mode == COBSOC
				Set_Bit(TCCR0 , TCCR0_COM00);
				Set_Bit(TCCR0 , TCCR0_COM01);
			#else
						#warning (" Wrong Configuration !!")
			#endif
		}
		switch(Copy_u8Pre_Scalar)
		{
			case(Pre_Scalar_0):Set_Bit(TCCR0 , TCCR0_CS00);Clear_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);break;
			case(Pre_Scalar_8):Clear_Bit(TCCR0 , TCCR0_CS00);Set_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);break;
			case(Pre_Scalar_64):Set_Bit(TCCR0 , TCCR0_CS00);Set_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);break;
			case(Pre_Scalar_256):Clear_Bit(TCCR0 , TCCR0_CS00);Clear_Bit(TCCR0 , TCCR0_CS01);Set_Bit(TCCR0 , TCCR0_CS02);break;
			case(Pre_Scalar_1024):Set_Bit(TCCR0 , TCCR0_CS00);Clear_Bit(TCCR0 , TCCR0_CS01);Set_Bit(TCCR0 , TCCR0_CS02);break;
			default:Clear_Bit(TCCR0 , TCCR0_CS00);Set_Bit(TCCR0 , TCCR0_CS01);Clear_Bit(TCCR0 , TCCR0_CS02);
		}
	}
/************************************************/
/*					Timer 1 					*/
/************************************************/


/************************************************/
/*					Timer 2 					*/
/************************************************/


/************************************************/
/*					General 					*/
/************************************************/
void Timer_VidPwm_Duty_Cycle(u8 Copy_u8Timer,u8 Copy_u8Duty_Cycle)
	{
	u8 Local_u8Variable=((Copy_u8Duty_Cycle*255ul)/100ul);
		switch(Copy_u8Timer)
		{
			case(Timer_0):OCR0=Local_u8Variable;break;
			case(Timer_1):OCR1AL=Local_u8Variable;OCR1BL=Local_u8Variable;break;
			case(Timer_2):OCR2=Local_u8Variable;break;
		}
	}



/*-------------------------------------------------------------------------------------------------------------------------------------------*/
/*------------------------------------------------------------------- ISR -------------------------------------------------------------------*/
/*-------------------------------------------------------------------------------------------------------------------------------------------*/


/****************************************************************/
/*							Timer 0 							*/
/****************************************************************/

/*------------------ Over_flow_ISR --------------------*/
static void (*Timer_0_Overflow_Inturrept_Function)(void)=NULL;
void Timer_0_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=NULL)
	{
		Timer_0_Overflow_Inturrept_Function = Copy_VidInturrept;
	}
}
void __vector_11(void) __attribute__((signal));
void __vector_11(void)
{
	if(Timer_0_Overflow_Inturrept_Function!=NULL)
	{
		Timer_0_Overflow_Inturrept_Function();
	}
}
/*-------------------- Compare_Match_ISR ------------------*/
static void (*Timer_0_Compare_Match_Inturrept_Function)(void)=NULL;
void Timer_0_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void))
{
	if(Copy_VidInturrept!=NULL)
	{
		Timer_0_Compare_Match_Inturrept_Function = Copy_VidInturrept;
	}
}
void __vector_10(void) __attribute__((signal));
void __vector_10(void)
{
	if(Timer_0_Compare_Match_Inturrept_Function!=NULL)
	{
		Timer_0_Compare_Match_Inturrept_Function();
	}
}
/****************************************************************/
/*							Timer 1 							*/
/****************************************************************/


/****************************************************************/
/*							Timer 2 							*/
/****************************************************************/




