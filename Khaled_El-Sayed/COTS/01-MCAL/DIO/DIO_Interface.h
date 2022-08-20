/*File Guard*/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*CONSTANTS_DIO*/
typedef enum{INPUT,OUTPUT,Port_A=0,Port_B,Port_C,Port_D,LOW=0,HI,Pin_0=0,Pin_1,Pin_2,Pin_3,Pin_4,Pin_5,Pin_6,Pin_7,FALSE=0,TRUE}Constants_DIO;
typedef enum{ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHTH,NINE,TEN}Constants_Numbres;


/*OPTIONS FOR SINGLE BIN*/
void DIO_VidInternal_Pin_Bull_Up(u8 Copy_u8Port,u8 Copy_u8Pin);							/*INTERNAL PIN PULL UP*/
void DIO_VidSet_Pin_Direction(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction);		/*SET PIN Direction*/
void DIO_VidSet_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Value);				/*SET PIN Value*/
void DIO_VidToggle_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin);								/*TOGGLE PIN Value*/
void DIO_VidGet_Pin_Value(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *Copy_Pu8Pin_Value);			/*Get PIN Value*/


/*OPTIONS FOR SINGLE PORT*/
void DIO_VidInternal_Port_Bull_Up(u8 Copy_u8Port);										/*INTERNAL PORT PULL UP*/
void DIO_VidSet_Whole_Port_Direction(u8 Copy_u8Port,u8 Copy_u8Direction);				/*SET Whole PORT Direction*/
void DIO_VidSet_Port_Direction(u8 Copy_u8Port,u8 Copy_u8Direction);						/*SET PORT Direction*/
void DIO_VidSet_Port_Value(u8 Copy_u8Port,u8 Copy_u8Value);								/*SET PORT Value*/
void DIO_VidToggle_Port_Value(u8 Copy_u8Port);											/*Get PORT Value*/
void DIO_VidGet_Port_Value(u8 Copy_u8Port,u8 *Copy_Pu8Port_Value);						/*Get PIN Value*/


#endif
/* DIO_INTERFACE_H_ */
