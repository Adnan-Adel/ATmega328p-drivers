/*
 * ext_interrupt.h
 *
 * Created: 7/7/2023 3:06:25 PM
 *  Author: Adnan
 */ 


#ifndef EXT_INTERRUPT_H_
#define EXT_INTERRUPT_H_

#include <stdlib.h>
#include "../DIO/dio.h"

// SREG pins
#define I		7		// Global Interrupt Enable

// EICRA pins
// Interrupt Sense Control 0
#define ISCOO	0
#define ISC01	1
// Interrupt Sense Control 1
#define ISC1O	2
#define ISC11	3

// EIMSK pins
#define INT0	0		// External Interrupt Request 0 Enable
#define INT1	1		// External Interrupt Request 1 Enable

// EIFR pins
#define INTF0	0		// External Interrupt Flag 0
#define INTF1	1		// External Interrupt Flag 1

/* ----------------------------------------- Macro Functions ----------------------------------------- */
/* This macro will enable global Interrupt */
#define INTERRUPT_GlobalInterruptEnable()		(SET_BIT(SREG, I))

/* This macro will disable global Interrupt */
#define INTERRUPT_GlobalInterruptDisable()		(CLEAR_BIT(SREG, I))


/* This routine sets the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptEnable()				(SET_BIT(EIMSK, INT0))

/* This routine clears the interrupt enable for the external interrupt, INT0 */
#define EXT_INT0_InterruptDisable()				(CLEAR_BIT(EIMSK, INT0))

/* This routine clears the interrupt flag for the external interrupt, INT0 */
#define EXT_INT0_InterruptFlagClear()			(SET_BIT(EIFR, INTF0))               

/* This routine sets the edge detect of the external interrupt, INT0 to rising edge */
#define EXTERNAL_IN0_RisingEdgeSet()			(EICRA= 0x03)               

/* This routine sets the edge detect of the external interrupt, INT0 to falling edge */
#define EXTERNAL_IN0_FallingEdgeSet()			(EICRA= 0x02)
            
			
/* This routine sets the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptEnable()				(SET_BIT(EIMSK, INT1))

/* This routine clears the interrupt enable for the external interrupt, INT1 */
#define EXT_INT1_InterruptDisable()				(CLEAR_BIT(EIMSK, INT1))

/* This routine clears the interrupt flag for the external interrupt, INT1 */
#define EXT_INT1_InterruptFlagClear()			(CLEAR_BIT(EIFR, INTF1))

/* This routine sets the edge detect of the external interrupt, INT1 to rising edge */
#define EXTERNAL_IN1_RisingEdgeSet()			(EICRA= 0x0C)

/* This routine sets the edge detect of the external interrupt, INT1 to falling edge */
#define EXTERNAL_IN1_FallingEdgeSet()			(EICRA= 0x08)

/* ----------------------------------------- Data Type Declaration ----------------------------------------- */
typedef enum
{
	INTERRUPT_EXTERNAL_INT0= 0,
	INTERRUPT_EXTERNAL_INT1
}Interrupt_INTx_src;

typedef enum
{
	INTERRUPT_FALLING_EDGE= 0,
	INTERRUPT_RISING_EDGE
}Interrupt_INTx_edge;

/* ----------------------------------------- Functions Declaration ----------------------------------------- */
void Interrupt_INTx_Init(Interrupt_INTx_src _src, Interrupt_INTx_edge _edge, void (*EXT_INTx_InterruptHandler)(void));

void INT0_ISR(INT0_vect);
void INT1_ISR(INT1_vect);

#endif /* EXT_INTERRUPT_H_ */