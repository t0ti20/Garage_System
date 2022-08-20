/* File Guard */
#ifndef _ADC_INTERRUPT_INTERFACE_H_
#define _ADC_INTERRUPT_INTERFACE_H_

/*ADC Functions*/
void ADC_VidInitialization ();
void ADC_VidAsync_Reading (u8 Copy_u8Channel,u8 *Copy_u8Reading);
void ADC_VidAsync_Mapped_Reading (u8 Copy_u8Channel,u32 Copy_u8Min,u32 Copy_u8Max,u32 * Copy_u32Reading);

#endif
/* _EXTERNAL_INTERRUPT_INTERFACE_H_*/
