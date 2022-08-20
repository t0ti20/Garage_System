/*File Guard*/
#ifndef SEVEN_SEGMENT_INTERFACE_H_
#define SEVEN_SEGMENT_INTERFACE_H_


/*Seven Segment Basic Options*/
void Seven_Segment_VidSend_One_Number(u8 Copy_u8Number);	  					   /*Use Only One 7-Segment*/
void Seven_Segment_VidSend_Two_Number(u8 Copy_u8Number_1,u8 Copy_u8Number_2);      /*Use TWO 7-Segments*/
void Seven_Segment_VidCount(u8 Copy_u8Max_number,u16 Copy_u8Delay_Ms);      	   /*Count With 7-Segment*/
void Seven_Segment_VidSpecial_Character(u8 Copy_u8Character);			 		   /*Special Character With 7-Segment*/

#endif
/* SEVEN_SEGMENT_INTERFACE_H_ */
