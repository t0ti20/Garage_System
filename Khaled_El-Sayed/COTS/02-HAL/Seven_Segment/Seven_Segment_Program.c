/*------------------------------- INCLUDE -------------------------------*/
#include <avr/delay.h>
#include "../../04-Library/Standard_Types.h"
#include "../../01-MCAL/DIO/DIO_Interface.h"
#include "Seven_Segment_Config.h"
#include "Seven_Segment_Interface.h"


/*------------------------------ Seven_Segment_Display_One_Digit ------------------------------*/

void Seven_Segment_VidSend_One_Number(u8 Copy_u8Number)
{
	if(Copy_u8Number<10)
	{
		u8 Local_u8Seven_Segment_Array [10] = Seven_Segment_Array ;
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,HI);
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Copy_u8Number]);
	}
}


/*------------------------------ Seven_Segment_Display_One_Digit ------------------------------*/

void Seven_Segment_VidCount(u8 Copy_u8Max_number,u16 Copy_u8Delay_Ms)
{
	if(Copy_u8Max_number<10)
	{
		u8 Local_u8Counter  = 0;
		u8 Local_u8Seven_Segment_Array [10] = Seven_Segment_Array ;
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,HI);
		for(Local_u8Counter=0 ; Local_u8Counter<=Copy_u8Max_number ; Local_u8Counter++)
		{
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Local_u8Counter]);
		_delay_ms(Copy_u8Delay_Ms);
		}
	}
}


/*----------------------------- Seven_Segment_Display_Two_Digit -----------------------------*/

void Seven_Segment_VidSend_Two_Number(u8 Copy_u8Number_1,u8 Copy_u8Number_2)
{
	if(Copy_u8Number_1<10 && Copy_u8Number_2<10)
	{
		u8 Local_u8Seven_Segment_Array [10] = Seven_Segment_Array ;
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,HI);
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Copy_u8Number_1]);
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,LOW);
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_2_Pin,HI);
		DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Local_u8Seven_Segment_Array[Copy_u8Number_2]);
		DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_2_Pin,LOW);
	}
}


/*----------------------------- Seven_Segment_Special_Character -----------------------------*/

void Seven_Segment_VidSpecial_Character(u8 Copy_u8Character)
{
	DIO_VidSet_Pin_Value(Seven_Segment_Enable_Port,Seven_Segment_Enable_1_Pin,HI);
	DIO_VidSet_Port_Value(Seven_Segment_Data_Port,Copy_u8Character);
}


