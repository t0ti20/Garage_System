/* File Guard */
#ifndef _TIMER_INTERFACE_H_
#define _TIMER_INTERFACE_H_


/************************************************/
/*					Timer 0 					*/
/************************************************/
	void Timer_0_VidInitialization (u8 Copy_u8Mode,u8 Copy_u8OCR_Value,u8 Copy_u8Compare_Match_Interrupt,u8 Copy_u8Over_Flow_Interrupt,u8 Copy_u8Pre_Scalar);
	void Timer_0_VidCompare_Match_Inturrept(void(*Copy_VidInturrept)(void));
	void Timer_0_VidOverflow_Inturrept(void(*Copy_VidInturrept)(void));

/************************************************/
/*					General 					*/
/************************************************/
	void Timer_VidPwm_Duty_Cycle(u8 Copy_u8Timer,u8 Copy_u8Duty_Cycle);

#endif
/*_TIMER_INTERFACE_H_*/
