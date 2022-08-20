/*------------------------------- INCLUDE -------------------------------*/
#include "avr/delay.h"
#include "../../04-Library/Standard_Types.h"
#include "../../01-MCAL/DIO/DIO_Interface.h"
#include "LCD_Interface.h"
#include "LCD_Config.h"


/*------------------------- Send_Command -------------------------*/

void LCD_VidSend_Command(u8 Copy_u8Command)
{
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RS_PIN,LOW);					/*SET RS PIN AS LOW*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RW_PIN,LOW);					/*SET RW PIN AS LOW TO WRITE*/
	DIO_VidSet_Port_Value(LCD_DATA_PORT,Copy_u8Command);				/*SEND COMMAND*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);					/*SET ENABLE PIN*/
	_delay_ms(3);														/*DELAY*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);					/*CLR ENABLE PIN*/
}


/*------------------------- Send_Data -------------------------*/

void LCD_VidSend_Data(u8 Copy_u8Data)
{
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RS_PIN,HI);					/*SET RS PIN AS HI*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_RW_PIN,LOW);					/*SET RW PIN AS LOW TO WRITE*/
	DIO_VidSet_Port_Value(LCD_DATA_PORT,Copy_u8Data);					/*SEND COMMAND*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,HI);					/*SET ENABLE PIN*/
	_delay_ms(3);														/*DELAY*/
	DIO_VidSet_Pin_Value(LCD_CTRL_PORT,LCD_E_PIN,LOW);					/*CLR ENABLE PIN*/
}


/*------------------------- Set_Position -------------------------*/

void LCD_VidSet_Position(u8 Copy_u8x_location,u8 Copy_u8y_location)
{
	LCD_VidSend_Command((128|(((Copy_u8y_location)*0x40)+Copy_u8x_location)));
}


/*------------------------- Special_Character -------------------------*/

void LCD_VidSend_Special_Character(u8 *Copy_u8Pattern,u8 Copy_u8Pattern_Location,u8 Copy_u8x_location,u8 Copy_u8y_location)
{
	LCD_VidSend_Command(64+8*Copy_u8Pattern_Location);
	for(u8 i=0;i<8;i++)
	{
		LCD_VidSend_Data(Copy_u8Pattern[i]);
	}
	LCD_VidSet_Position(Copy_u8x_location,Copy_u8y_location);
	LCD_VidSend_Data(Copy_u8Pattern_Location);
}


/*------------------------- Special_Character -------------------------*/

void LCD_VidSend_String(u8 *Copy_u8String)
{
	u8 Local_u8Counter=0;
	while(((Copy_u8String[Local_u8Counter])!=0)&&Local_u8Counter<16)
	{
		LCD_VidSend_Data(Copy_u8String[Local_u8Counter]);
		Local_u8Counter++;
	}
}


/*------------------------- Special_Character -------------------------*/

void LCD_VidClear(void)
{
	u8 Local_u8String[16]="                ";
		LCD_VidSet_Position(0,0);
		LCD_VidSend_String(Local_u8String);
		LCD_VidSet_Position(0,1);
		LCD_VidSend_String(Local_u8String);
		LCD_VidSet_Position(0,0);
}


/*------------------------- Initialization -------------------------*/

void LCD_VidInitialization(void)
{
	DIO_VidSet_Whole_Port_Direction(LCD_DATA_PORT,OUTPUT);				/* Port Direction Select */
	DIO_VidSet_Port_Direction(LCD_CTRL_PORT,0x07);
	_delay_ms(40);														/*DELAY*/
	LCD_VidSend_Command(0b00111100);									/*1ST FROM DATA SHEET(Function Set)*/
	LCD_VidSend_Command(0b00001100);									/*2ND FROM DATA SHEET(Display On-Off)*/
	LCD_VidSend_Command(HI);											/*3RD FROM DATA SHEET(Display Clear)*/
}
