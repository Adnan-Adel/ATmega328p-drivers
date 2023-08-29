#ifndef __REGISTERS_H__
#define __REGISTERS_H__

#include "std_types.h"
#include "Bit_Masking.h"

#define SREG 				(*(volatile uint8_t*)0x5F)			    // AVR Status Register
#define MCUCR 				(*(volatile uint8_t*)0x55)				// MCU Control Register


/* ----------------------- EEPROM Registers ----------------------- */
#define EEPROM_EEARL		(*(volatile uint8_t*)0x41)				// The EEPROM Address Register Low
#define EEPROM_EEARH		(*(volatile uint8_t*)0x42)				// The EEPROM Address Register High
#define EEPROM_EEDR			(*(volatile uint8_t*)0x40)				// The EEPROM Data Register
#define EEPROM_EECR			(*(volatile uint8_t*)0x3F)				// The EEPROM Control Register

/* ----------------------- CLOCK Registers ----------------------- */
#define CLOCK_OSCCAL		(*(volatile uint8_t*)0x66)				// Oscillator Calibration Register
#define CLOCK_CLKPR 		(*(volatile uint8_t*)0x66)				// Clock Prescale Register
#define CLOCK_SMCR			(*(volatile uint8_t*)0x53)				// Sleep Mode Control Register

#define PRR					(*(volatile uint8_t*)0x64)				// Power Reduction Register

/* ----------------------- Watch Dog Timer Registers ----------------------- */
#define WDT_MCUSR			(*(volatile uint8_t*)0x54)				// MCU Status Register
#define WDT_WDTCSR			(*(volatile uint8_t*)0x60)				// Watchdog Timer Control Register

/* ----------------------- GPIO Registers ----------------------- */
// PORTB
#define GPIO_PORTB			(*(volatile uint8_t*)0x25)			   // The Port B Data Register
#define GPIO_DDRB			(*(volatile uint8_t*)0x24)			   // The Port B Direction Register
#define GPIO_PINB			(*(volatile uint8_t*)0x23)			   // The Port B Input Pins Address
// PORTC
#define GPIO_PORTC			(*(volatile uint8_t*)0x28)			   // The Port C Data Register
#define GPIO_DDRC			(*(volatile uint8_t*)0x27)			   // The Port C Direction Register
#define GPIO_PINC			(*(volatile uint8_t*)0x26)			   // The Port C Input Pins Address
// PORTD
#define GPIO_PORTD			(*(volatile uint8_t*)0x2B)			   // The Port D Data Register
#define GPIO_DDRD			(*(volatile uint8_t*)0x2A)			   // The Port D Direction Register
#define GPIO_PIND			(*(volatile uint8_t*)0x29)			   // The Port D Input Pins Address



#endif
