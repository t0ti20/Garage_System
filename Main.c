/*
 * Main.c
 *
 *  Created on: Aug 17, 2021
 *      Author: User
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Admin_Password_Add			10		/* 1 + 2 + 3 + 4 == 10 */
#define Admin_Password_Size 		4		/* 1 , 2 , 3 , 4 */
#define Asci_Zero					48
#define Maximum_Clients				50
#include <util/delay.h>
#include "Khaled_El-Sayed/COTS/04-Library/Standard_Types.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/DIO/DIO_Interface.h"
#include "Khaled_El-Sayed/COTS/02-HAL/LCD/LCD_Config.h"
#include "Khaled_El-Sayed/COTS/02-HAL/LCD/LCD_Interface.h"
#include "Khaled_El-Sayed/COTS/02-HAL/Keypad/Keypad_Config.h"
#include "Khaled_El-Sayed/COTS/02-HAL/Keypad/Keypad_Interface.h"
#include "Khaled_El-Sayed/COTS/02-HAL/Seven_Segment/Seven_Segment_Config.h"
#include "Khaled_El-Sayed/COTS/02-HAL/Seven_Segment/Seven_Segment_Interface.h"
#include "Khaled_El-Sayed/COTS/02-HAL/DC_Motor/DC_Motor_Config.h"
#include "Khaled_El-Sayed/COTS/02-HAL/DC_Motor/DC_Motor_Interface.h"
#include "Khaled_El-Sayed/COTS/02-HAL/Stepper_Motor/Stepper_Motor_Config.h"
#include "Khaled_El-Sayed/COTS/02-HAL/Stepper_Motor/Stepper_Motor_Interface.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/GIE/GIE_Interface.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/External_Interrupt/External_Interrupt_Interface.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/ADC/ADC_Config.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/ADC/ADC_Interface.h"
//#include "Khaled_El-Sayed/COTS/01-MCAL/Timer/Timer_Private.h"
//#include "Khaled_El-Sayed/COTS/01-MCAL/Timer/Timer_Interface.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/SPI/SPI_Interface.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/SPI/SPI_Private.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/TWI/TWI_Interface.h"
#include "Khaled_El-Sayed/COTS/01-MCAL/TWI/TWI_Private.h"

typedef struct {u16 id;u8 state;u8 time;}data;
data parking_data[Maximum_Clients];
u8 Global_Counter=0;
u8 User_Select_u8(void);
u8 Password_u8(void);
u8 ID_Check_u8(u8 Copy_u8id);
u8 Admin_u8(void);
void User_Vid(void);
void New_User_Vid(void);
void Active_Cars_Vid(void);

void main(void)
{
	LCD_VidInitialization();
	Keypad_VidInitialization();
	while(TRUE)
	{
		User_Select_u8();
	}
}

u8 User_Select_u8(void)
{
	u8 Option1[16]="1)Parking";
	u8 Option2[16]="2)Admin";
	u8 Wrong[16]="Wrong Input..";
	u8 global_flag=TRUE;
	u8 password_flag=TRUE;
	u8 data=0;
	while(global_flag)
	{
		LCD_VidClear();
		LCD_VidSet_Position(0,0);
		LCD_VidSend_String(Option1);
		LCD_VidSet_Position(0,1);
		LCD_VidSend_String(Option2);
		data=Keypad_u8Get_Pressed_Key_Wait()-48;
		switch(data)
		{
			case(ONE):User_Vid();break;
			case(TWO):password_flag=Password_u8();while(password_flag)password_flag=Admin_u8();break;
			default:LCD_VidClear();LCD_VidSend_String(Wrong);_delay_ms(1000);
		}
	}
	return TRUE;
}


u8 Admin_u8(void)
{
	u8 input;
	u8 flag=TRUE;
	u8 Option1[16]="1) Active Cars";
	u8 Option2[16]="2) All Cars";
	u8 Wrong[16]="Wrong Input!!";
	while(flag)
	{
		LCD_VidClear();
		LCD_VidSend_String(Option1);
		LCD_VidSet_Position(0,1);
		LCD_VidSend_String(Option2);
		input=Keypad_u8Get_Pressed_Key_Wait()-48;
		switch(input)
		{
			case(ONE):Active_Cars_Vid();break;
			case(TWO):break;
			case('O'-48):flag=FALSE;break;
			default:LCD_VidClear();LCD_VidSend_String(Wrong);_delay_ms(1000);
		}
	}
	return flag;
}

void Active_Cars_Vid(void)
{
	u8 Option1[16]="ID : ";
	u8 Option2[16]="Time : ";
	u8 Wrong[16]="No Active Cars";
	u8 Copy_u8Count=ZERO;
	u8 flag=TRUE;
	u16 Num[10];
	while(flag)
	{
		if(Keypad_u8Get_Pressed_Key()=='O')break;
		for(u8 i=0;i<Maximum_Clients;i++)
		{
			if(parking_data[i].state==HI)
			{
				LCD_VidClear();
				LCD_VidSend_String(Option1);
				itoa(parking_data[i].id,Num,10);
				LCD_VidSend_String(Num);
				LCD_VidSet_Position(0,1);
				LCD_VidSend_String(Option2);
				_delay_ms(500);
				Copy_u8Count++;
			}
		}
		if(Copy_u8Count==ZERO){LCD_VidClear();LCD_VidSend_String(Wrong);_delay_ms(500);flag=FALSE;}
	}
}



void User_Vid(void)
{
	u8 input;
	u8 flag=TRUE;
	u8 Option1[16]="1) In <-";
	u8 Option2[16]="2) Out ->";
	u8 Wrong[16]="Wrong Input!!";
	while(flag)
	{
		LCD_VidClear();
		LCD_VidSend_String(Option1);
		LCD_VidSet_Position(0,1);
		LCD_VidSend_String(Option2);
		input=Keypad_u8Get_Pressed_Key_Wait()-48;
		switch(input)
		{
			case(ONE):New_User_Vid();break;
			case(TWO):break;
			case('O'-48):flag=FALSE;break;
			default:LCD_VidClear();LCD_VidSend_String(Wrong);_delay_ms(1000);
		}
	}
}

void New_User_Vid(void)
{
	u32 input;
	u8 flag=TRUE;
	u32 data=0;
	u8 Option1[16]="Please Enter ID";
	u8 Option2[16]="Invalid ID !!";
	while(flag)
	{
		LCD_VidClear();
		LCD_VidSend_String(Option1);
		LCD_VidSet_Position(0,1);
		for(u32 i=0,s=1000; i<Admin_Password_Size ; i++,s/=10)
		{
			input=Keypad_u8Get_Pressed_Key_Wait();
			LCD_VidSend_Data(input);
			data+=((input-48)*s);
		}
		if(ID_Check_u8(data)==FALSE)
		{
			LCD_VidClear();
			LCD_VidSend_String(Option2);
			_delay_ms(500);
		}
		else{flag=FALSE;}
	}
	parking_data[Global_Counter].id=data;
	parking_data[Global_Counter].state=HI;
	/*Timer Start*/
	Global_Counter++;
}

u8 ID_Check_u8(u8 Copy_u8id)
{
	for(u8 i=0 ; i<Maximum_Clients;i++)
	{
		if((parking_data[i].state==HI)&&(parking_data[i].id==Copy_u8id))
		{
			return FALSE;
		}
	}
	return TRUE;
}

u8 Password_u8(void)
{
	u8 data,password=ZERO;
	u8 flag=TRUE;
	u8 Enter[16]="Enter Password";
	u8 Wrong[16]="Wrong Password";
	u8 Welcome[16]="Welcome...";
	while(flag)
	{
		LCD_VidClear();
		LCD_VidSet_Position(0,0);
		LCD_VidSend_String(Enter);
		LCD_VidSet_Position(0,1);
		for(u8 c=0;c<Admin_Password_Size;c++)
		{
			data=Keypad_u8Get_Pressed_Key_Wait();
			if(data=='O'){return FALSE;}
			LCD_VidSend_Data('*');
			LCD_VidSend_Data(' ');
			data-=Asci_Zero;
			password+=data;
		}
		if(password == Admin_Password_Add)
		{
			flag=FALSE;
			LCD_VidInitialization();
			LCD_VidSend_String(Welcome);
			_delay_ms(1000);
			return TRUE;
		}
		else
		{
			LCD_VidInitialization();
			LCD_VidSend_String(Wrong);
			_delay_ms(1000);
			LCD_VidInitialization();
		}
	}
	return FALSE;
}
