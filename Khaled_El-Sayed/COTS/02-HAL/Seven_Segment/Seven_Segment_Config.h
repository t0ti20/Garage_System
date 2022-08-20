/*File Guard*/
#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

/*Constant Values*/
#define Seven_Segment_Data_Port	Port_C      					  		          /*7_Segment Used Port*/
#define Seven_Segment_Enable_Port Port_D									      /*7_Segment Enable Port*/
#define Seven_Segment_Enable_1_Pin Pin_0									   	  /*First Segment Enable Port*/
#define Seven_Segment_Enable_2_Pin Pin_1										  /*Second Segment Enable Port*/
#define Seven_Segment_Array {0xC0,0xf9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90}   /*Please Use Ports From "0" To "7" For Pins "A" To "G" */

/*Special Character*/
#define Left_Arrow  0x06
#define Right_Arrow 0x30

#endif
/* SEVEN_SEGMENT_CONFIG_H_ */
