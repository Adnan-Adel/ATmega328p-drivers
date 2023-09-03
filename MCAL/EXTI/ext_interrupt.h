/*
 * exti.h
 *
 *  Created on: Sep 2, 2023
 *      Author: Adnan
 */

#ifndef MCAL_EXTI_EXT_INTERRUPT_H_
#define MCAL_EXTI_EXT_INTERRUPT_H_

/* ------------------------------- Includes ------------------------------- */
#include "../GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */
// SREG pins
#define I						7		// Global Interrupt Enable

// EICRA pins
// Interrupt Sense Control 0
#define ISCOO					0
#define ISC01					1
// Interrupt Sense Control 1
#define ISC1O					2
#define ISC11					3

// EIMSK pins
#define INT0					0		// External Interrupt Request 0 Enable
#define INT1					1		// External Interrupt Request 1 Enable

// EIFR pins
#define INTF0					0		// External Interrupt Flag 0
#define INTF1					1		// External Interrupt Flag 1

// External Interrupts
#define EXTI_INT0				0
#define EXTI_INT1				1

// External Interrupt Edge
#define EXTI_RISING_EDGE		0
#define EXTI_FALLING_EDGE		1

/* ------------------------------- Macro Functions ------------------------------- */
/* Function like Macro to Enable Global Interrupt */
#define INTERRUPT_GlobalInterruptEnable()				(SET_BIT(SREG,I))

/* Function like Macro to Disable Global Interrupt */
#define INTERRUPT_GlobalInterruptDisable()				(CLEAR_BIT(SREG,I))

/* Function like Macro to Enable external interrupts (INT0 or INT1) */
#define EXTI_InterruptEnable(_EXTI_SRC)					(SET_BIT(EXTI_EIMSK, _EXTI_SRC))

/* Function like Macro to Disable external interrupts (INT0 or INT1) */
#define EXTI_InterruptDisable(_EXTI_SRC)				(CLEAR_BIT(EXTI_EIMSK, _EXTI_SRC))

/* Function like Macro to Clear the Interrupt Flag for external interrupt INT0 */
#define EXT_INT0_InterruptFlagClear()					(SET_BIT(EXTI_EIFR, INTF0))

/* Function like Macro to Clear the Interrupt Flag for external interrupt INT1 */
#define EXT_INT1_InterruptFlagClear()					(SET_BIT(EXTI_EIFR, INTF1))

/* Function like Macro to set the edge detect of the external interrupt, INT0 to rising edge */
#define EXTERNAL_IN0_RisingEdgeSet()					(EXTI_EICRA= 0x03)

/* Function like Macro to set the edge detect of the external interrupt, INT0 to falling edge */
#define EXTERNAL_IN0_FallingEdgeSet()					(EXTI_EICRA= 0x02)

/* Function like Macro to set the edge detect of the external interrupt, INT1 to rising edge */
#define EXTERNAL_IN1_RisingEdgeSet()					(EXTI_EICRA= 0x0C)

/* Function like Macro to set the edge detect of the external interrupt, INT1 to falling edge */
#define EXTERNAL_IN1_FallingEdgeSet()					(EXTI_EICRA= 0x08)

/* ------------------------------- data types declarations ------------------------------- */

/* ----------------------- Functions Declarations ----------------------- */
std_return_type_t Interrupt_INTx_init(uint8_t ext_intx_src, uint8_t ext_intx_edge, void (*EXT_INTx_InterruptHandler)(void));

std_return_type_t Interrupt_INTx_Edge_init(uint8_t ext_intx_src, uint8_t ext_intx_edge);


#endif /* MCAL_EXTI_EXT_INTERRUPT_H_ */
