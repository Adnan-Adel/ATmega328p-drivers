/*
 * Registers.h
 *
 * Created: 2/12/2023 1:25:46 PM
 *  Author: LAP TECH
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

#include "Bit_Masking.h"
#include "std_types.h"

/*******************************************************************/
/*      DIO registers
/******************************************************************/

// PORTB registers
#define PINB	(*(volatile uint8_t *)0x23)
#define DDRB	(*(volatile uint8_t *)0x24)
#define PORTB	(*(volatile uint8_t *)0x25)

// PORTC registers
#define PINC	(*(volatile uint8_t *)0x26)
#define DDRC	(*(volatile uint8_t *)0x27)
#define PORTC	(*(volatile uint8_t *)0x28)

// PORTD registers
#define PIND	(*(volatile uint8_t *)0x29)
#define DDRD	(*(volatile uint8_t *)0x2A)
#define PORTD	(*(volatile uint8_t *)0x2B)

/*******************************************************************/
/*     EXTERNAL INTERRUPT registers
/******************************************************************/
#define SREG	(*(volatile uint8_t *)0x5F)
#define MCUCR	(*(volatile uint8_t *)0x55)
#define EICRA	(*(volatile uint8_t *)0x69)
#define EIMSK	(*(volatile uint8_t *)0x3D)
#define EIFR	(*(volatile uint8_t *)0x3C)

/*******************************************************************/
/*     ADC registers
/******************************************************************/
#define ADMUX	(*(volatile uint8_t *)0x7C)
#define ADCSRA	(*(volatile uint8_t *)0x7A)
#define ADCH	(*(volatile uint8_t *)0x79)
#define ADCL	(*(volatile uint8_t *)0x78)

/*******************************************************************/
/*     UART registers
/******************************************************************/
#define UDR		(*(volatile uint8_t *)0xC6)
#define UBRRH	(*(volatile uint8_t *)0xC5)
#define UBRRL	(*(volatile uint8_t *)0xC4)
#define UCSRC	(*(volatile uint8_t *)0xC2)
#define UCSRB	(*(volatile uint8_t *)0xC1)
#define UCSRA	(*(volatile uint8_t *)0xC0)


#endif /* REGISTERS_H_ */