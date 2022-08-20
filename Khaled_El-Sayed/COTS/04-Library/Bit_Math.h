#ifndef _BIT_MATH_H_
#define _BIT_MATH_H_

		/* Set Bit */
#define Set_Bit(Reg,Bit_Num)  Reg|=1<<Bit_Num

		/* Clear Bit */
#define Clear_Bit(Reg,Bit_Num)  Reg&=~(1<<Bit_Num)

		/* Toggle Bit */
#define Toggle_Bit(Reg,Bit_Num)  Reg^=(1<<Bit_Num)

		/* GET_BIT */
#define Get_Bit(Reg,Bit_Num)   ((Reg>>Bit_Num)&1)


#endif