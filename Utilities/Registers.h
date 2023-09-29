#ifndef __REGISTERS_H__
#define __REGISTERS_H__

#include "std_types.h"
#include "Bit_Masking.h"

#define SREG 				(*(volatile uint8_t*)0x5F)					// AVR Status Register


/* ----------------------- Power Management Registers ----------------------- */
#define	SMCR				(*(volatile uint8_t*)0x53)					// Sleep Mode Control Register
#define MCUCR 				(*(volatile uint8_t*)0x55)					// MCU Control Register
#define PRR 				(*(volatile uint8_t*)0x64)					// Power Reduction Register

// PRR-Reg Bits
#define PRADC				0
#define PRUSART0			1
#define PRSPI				2
#define PRTIM1				3
#define PRTIM0				5
#define PRTIM2				6
#define PRTWI				7

/* ----------------------- EEPROM Registers ----------------------- */
#define EEPROM_EEARL		(*(volatile uint8_t*)0x41)					// The EEPROM Address Register Low
#define EEPROM_EEARH		(*(volatile uint8_t*)0x42)					// The EEPROM Address Register High
#define EEPROM_EEDR			(*(volatile uint8_t*)0x40)					// The EEPROM Data Register
#define EEPROM_EECR			(*(volatile uint8_t*)0x3F)					// The EEPROM Control Register

/* ----------------------- CLOCK Registers ----------------------- */
#define CLOCK_OSCCAL		(*(volatile uint8_t*)0x66)					// Oscillator Calibration Register
#define CLOCK_CLKPR 		(*(volatile uint8_t*)0x66)					// Clock Prescale Register
#define CLOCK_SMCR			(*(volatile uint8_t*)0x53)					// Sleep Mode Control Register

#define PRR					(*(volatile uint8_t*)0x64)					// Power Reduction Register

/* ----------------------- Watch Dog Timer Registers ----------------------- */
#define WDT_MCUSR			(*(volatile uint8_t*)0x54)					// MCU Status Register
#define WDT_WDTCSR			(*(volatile uint8_t*)0x60)					// Watchdog Timer Control Register

/* ----------------------- GPIO Registers ----------------------- */
// PORTB
#define GPIO_PORTB			(*(volatile uint8_t*)0x25)			   		// The Port B Data Register
#define GPIO_DDRB			(*(volatile uint8_t*)0x24)			  	 	// The Port B Direction Register
#define GPIO_PINB			(*(volatile uint8_t*)0x23)			   		// The Port B Input Pins Address
// PORTC
#define GPIO_PORTC			(*(volatile uint8_t*)0x28)			   		// The Port C Data Register
#define GPIO_DDRC			(*(volatile uint8_t*)0x27)			   		// The Port C Direction Register
#define GPIO_PINC			(*(volatile uint8_t*)0x26)			   		// The Port C Input Pins Address
// PORTD
#define GPIO_PORTD			(*(volatile uint8_t*)0x2B)			   		// The Port D Data Register
#define GPIO_DDRD			(*(volatile uint8_t*)0x2A)			   		// The Port D Direction Register
#define GPIO_PIND			(*(volatile uint8_t*)0x29)			   		// The Port D Input Pins Address

/* ----------------------- External Interrupt Registers ----------------------- */
#define EXTI_EICRA			(*(volatile uint8_t*)0x69)  		   		// External Interrupt Control Register
#define EXTI_EIMSK			(*(volatile uint8_t*)0x3D)			   		// External Interrupt Mask Register
#define EXTI_EIFR			(*(volatile uint8_t*)0x3C)			   		// External Interrupt Flag Register
#define EXTI_PCICR			(*(volatile uint8_t*)0x68)  		   		// Pin Change Interrupt Control Register
#define EXTI_PCIFR			(*(volatile uint8_t*)0x3B)  		   		// Pin Change Interrupt Flag Register
#define EXTI_PCMSK0			(*(volatile uint8_t*)0x6B)  		   		// Pin Change Mask Register 0
#define EXTI_PCMSK1			(*(volatile uint8_t*)0x6C)  		   		// Pin Change Mask Register 1
#define EXTI_PCMSK2			(*(volatile uint8_t*)0x6D)  		   		// Pin Change Mask Register 2

/* ----------------------- ADC Registers ----------------------- */
#define ADC_ADMUX			(*(volatile uint8_t*)0x7C)					// ADC Multiplexer Selection Register
#define ADC_ADCSRA			(*(volatile uint8_t*)0x7A)					// ADC Control and Status Register A
#define ADC_ADCL			(*(volatile uint8_t*)0x78)					// ADC Data Register Low
#define ADC_ADCH			(*(volatile uint8_t*)0x79)					// ADC Data Register High
#define ADC_ADCSRB			(*(volatile uint8_t*)0x7B)					// ADC Control and Status Register B
#define ADC_ DIDR0			(*(volatile uint8_t*)0x7E)					//  Digital Input Disable Register 0

/* ----------------------- TIMER0 Registers ----------------------- */
#define TIMER0_TCCR0A		(*(volatile uint8_t*)0x44)					// Timer/Counter0 Control Register A
#define TIMER0_TCCR0B		(*(volatile uint8_t*)0x45)					// Timer/Counter0 Control Register B
#define TIMER0_TCNT0		(*(volatile uint8_t*)0x46)					// Timer/Counter0 Register
#define TIMER0_OCR0A		(*(volatile uint8_t*)0x47)					// Output Compare Register A
#define TIMER0_OCR0B		(*(volatile uint8_t*)0x48)					// Output Compare Register B
#define TIMER0_TIMSK0		(*(volatile uint8_t*)0x6E)					// Timer/Counter0 Interrupt Mask Register
#define TIMER0_TIFR0		(*(volatile uint8_t*)0x35)					// Timer/Counter0 Interrupt Flag Register

// TIMSK0-Reg Bits
#define TOIE0				0
#define OCIE0A				1
#define OCIE0B				2

// TIFR0-Reg Bits
#define TOV0				0
#define OCF0A				1
#define OCF0B				2

/* ----------------------- USART Registers ----------------------- */
// USART I/O Data Register 0
#define UDR0				(*(volatile uint8_t*)0xC6)

// USART Baud Rate High Register
#define UBRR0H				(*(volatile uint8_t*)0xC5)

// USART Baud Rate Low Register
#define UBRR0L				(*(volatile uint8_t*)0xC4)

// USART Control and Status Register 0 C
#define UCSR0C				(*(volatile uint8_t*)0xC2)
#define UCPOL0				0
#define UCSZ00				1
#define UCSZ01				2
#define USBS0				3
#define UPM00				4
#define UPM01				5
#define UMSEL00				6
#define UMSEL01				7

// USART Control and Status Register 0 B
#define UCSR0B				(*(volatile uint8_t*)0xC1)
#define TXB80				0
#define RXB80				1
#define UCSZ02				2
#define TXEN0				3
#define RXEN0				4
#define UDRIE0				5
#define TXCIE0				6
#define RXCIE0				7

// USART Control and Status Register 0 A
#define UCSR0A				(*(volatile uint8_t*)0xC0)
#define MPCM0				0
#define U2X0				1
#define UPE0				2
#define DOR0				3
#define FE0					4
#define UDRE0				5
#define TXC0				6
#define RXC0				7

#endif
