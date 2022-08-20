/*------------------------------- INCLUDE -------------------------------*/
#include "../../04-Library/Bit_Math.h"
#include "../../04-Library/Standard_Types.h"
#include "GIE_private.h"
#include "GIE_interface.h"


/*------------------------- GIE Enable -------------------------*/
void GIE_VidEnable ()
{
	Set_Bit(SREG,SREG_I_Bit);
}


/*------------------------- GIE Disable -------------------------*/
void GIE_VidDisable (void)
{
	Clear_Bit(SREG,SREG_I_Bit);
}

