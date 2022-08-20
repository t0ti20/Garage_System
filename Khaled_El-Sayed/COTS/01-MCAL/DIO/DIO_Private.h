/*File Guard*/
#ifndef DIO_PRIVATE_H_
#define DIO_PRIVATE_H_

/*FOR A*/
#define PORTA *((volatile u8*)0X3B)
#define DDRA  *((volatile u8*)0X3A)
#define PINA  *((volatile u8*)0X39)
/*FOR B*/
#define PORTB *((volatile u8*)0X38)
#define DDRB  *((volatile u8*)0X37)
#define PINB  *((volatile u8*)0X36)
/*FOR C*/
#define PORTC *((volatile u8*)0X35)
#define DDRC  *((volatile u8*)0X34)
#define PINC  *((volatile u8*)0X33)
/*FOR D*/
#define PORTD *((volatile u8*)0X32)
#define DDRD  *((volatile u8*)0X31)
#define PIND  *((volatile u8*)0X30)

#endif
/* DIO_PRIVATE_H_ */