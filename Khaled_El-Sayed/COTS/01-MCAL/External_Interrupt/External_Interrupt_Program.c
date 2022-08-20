
#include  "../../04-Library/Bit_Math.h"
#include  "../../04-Library/Standard_Types.h"
#include  "External_Interrupt_Interface.h"
#include  "External_Interrupt_Private.h"
#include  "External_Interrupt_Config.h"




/*EXTI Enable */
void External_Interrupt_0_VidInitialization ()
{
	#if External_Interrupt_0_Sense == Low_Level			/* Sense Control */
		Clear_Bit(MCUCR , MCUCR_ISC00);
		Clear_Bit(MCUCR , MCUCR_ISC01);
	#elif External_Interrupt_0_Sense == On_Change
		Set_Bit(MCUCR , MCUCR_ISC00);
		Clear_Bit(MCUCR , MCUCR_ISC01);
	#elif External_Interrupt_0_Sense == Falling_Edge
		Clear_Bit(MCUCR , MCUCR_ISC00);
		Set_Bit(MCUCR , MCUCR_ISC01);
	#elif External_Interrupt_0_Sense == Rising_Edge
		Set_Bit(MCUCR , MCUCR_ISC00);
		Set_Bit(MCUCR , MCUCR_ISC01);
	#else
		#warning (" Wrong Configuration !!")
	#endif
	#if External_Interrupt_0_Enable == Enable		  /* Initial State */
		Set_Bit(GICR,GICR_Interrupt_0);
	#elif External_Interrupt_0_Enable == Enable
		Set_Bit(GICR,GICR_Interrupt_0);
	#else
		#warning (" Wrong Configuration !!")
	#endif
}


void External_Interrupt_1_VidInitialization ()
{
	/* Sense Control */
	#if External_Interrupt_1_Sense == Low_Level
		Clear_Bit(MCUCR , MCUCR_ISC10);
		Clear_Bit(MCUCR , MCUCR_ISC11);
	#elif External_Interrupt_1_Sense == On_Change
		Set_Bit(MCUCR , MCUCR_ISC10);
		Clear_Bit(MCUCR , MCUCR_ISC11);
	#elif External_Interrupt_1_Sense == Falling_Edge
		Clear_Bit(MCUCR , MCUCR_ISC10);
		Set_Bit(MCUCR , MCUCR_ISC11);
	#elif External_Interrupt_1_Sense == Rising_Edge
		Set_Bit(MCUCR , MCUCR_ISC10);
		Set_Bit(MCUCR , MCUCR_ISC11);
	#else
		#warning (" Wrong Configuration !! ")
	#endif
	/* Initial State */
	#if External_Interrupt_1_Enable == Enable
		Set_Bit(GICR,GICR_Interrupt_1);
	#elif External_Interrupt_1_Enable == Enable
		Set_Bit(GICR,GICR_Interrupt_1);
	#else
		#warning (" Wrong Configuration !! ")
	#endif
}

void External_Interrupt_2_VidInitialization ()
{
	#if External_Interrupt_2_Sense == Falling_Edge
		Clear_Bit(MCUCSR, MCUCSR_ISC2);
	#elif External_Interrupt_1_Enable == Enable
		Set_Bit(MCUCSR , MCUCSR_ISC2);
	#else
		#warning (" Wrong Configuration !! ")
	#endif
	/* Initial State */
	#if External_Interrupt_2_Enable   == ENABLE
		SET_BIT(GICR ,GICR_Interrupt_2);
	#elif EXTI_INT2_INITIAL_STATE == DISABLE
		Clear_Bit(GICR , GICR_Interrupt_2);
	#else
		#warning (" Wrong Configuration !!")
	#endif
}
