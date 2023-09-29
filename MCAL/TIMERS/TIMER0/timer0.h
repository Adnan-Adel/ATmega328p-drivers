/*
 * timer0.h
 *
 *  Created on: Sep 17, 2023
 *      Author: Adnan
 */

#ifndef MCAL_TIMERS_TIMER0_TIMER0_H_
#define MCAL_TIMERS_TIMER0_TIMER0_H_

/* ------------------------------- Includes ------------------------------- */
#include "../../GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */
/* ---------------------------- Waveform Generation Mode ------------------------ */
#define NORMAL										0
#define PWM_PHASE_CORRECT_0XFF_TOP					1
#define CTC											2
#define FAST_PWM_0XFF_TOP							3
#define PWM_PHASE_CORRECT_OCRA_TOP					5
#define FAST_PWM_OCRA_TOP							7

/* ---------------------------- Clock Source ------------------------ */
#define NO_CLK_SOURCE								0
#define SYS_CLK_NO_PRESCALER						1
#define SYS_CLK_DIV_BY_8_PRESCALER					2
#define SYS_CLK_DIV_BY_64_PRESCALER					3
#define SYS_CLK_DIV_BY_256_PRESCALER				4
#define SYS_CLK_DIV_BY_1024_PRESCALER				5
#define EXTERNAL_CLK_FALLING_EDGE					6
#define EXTERNAL_CLK_RISING_EDGE					7

/* ----------------------------  Compare Match-x ------------------------ */
#define CM_OCR0A									0
#define CM_OCR0B									1

/* ----------------------------  Compare Output Mode-A, non-PWM Mode ------------------------ */
#define DISCONNECT_OC0A								0
#define TOGGLE_OC0A_ON_CM							1
#define CLEAR_OC0A_ON_CM							2
#define SET_OC0A_ON_CM								3

/* ----------------------------  Compare Output Mode-B, non-PWM Mode ------------------------ */
#define DISCONNECT_OC0B								0
#define TOGGLE_OC0B_ON_CM							1
#define CLEAR_OC0B_ON_CM							2
#define SET_OC0B_ON_CM								3

/* ------------------------------- Macro Functions ------------------------------- */
#define TIMER0_MODULE_ENABLE()						CLEAR_BIT(PRR, PRTIM0)
#define TIMER0_MODULE_DISABLE()						SET_BIT(PRR, PRTIM0)

#define TIMER0_OVF_INTERRUPT_ENABLE()				SET_BIT(TIMER0_TIMSK0, TOIE0)
#define TIMER0_OCMA_INTERRUPT_ENABLE()				SET_BIT(TIMER0_TIMSK0, OCIE0A)
#define TIMER0_OCMB_INTERRUPT_ENABLE()				SET_BIT(TIMER0_TIMSK0, OCIE0B)

#define TIMER0_OVF_INTERRUPT_DISABLE()				CLEAR_BIT(TIMER0_TIMSK0, TOIE0)
#define TIMER0_OCMA_INTERRUPT_DISABLE()				CLEAR_BIT(TIMER0_TIMSK0, OCIE0A)
#define TIMER0_OCMB_INTERRUPT_DISABLE()				CLEAR_BIT(TIMER0_TIMSK0, OCIE0B)

#define TIMER0_OVF_INTERRUPT_FLAG_CLEAR()			SET_BIT(TIMER0_TIFR0, TOV0)
#define TIMER0_OCMA_INTERRUPT_FLAG_CLEAR()			SET_BIT(TIMER0_TIFR0, OCF0A)
#define TIMER0_OCMB_INTERRUPT_FLAG_CLEAR()			SET_BIT(TIMER0_TIFR0, OCF0B)

/* ------------------------------- data types declarations ------------------------------- */
typedef struct
{
	uint8_t Timer0_Waveform_Generation_Mode;
	uint8_t Timer0_Clock_Source;
	uint8_t Timer0_Preload_value;
	uint8_t Timer0_CMReg;			// A or B
	uint8_t Timer0_CM_Value;

	void (*TIMER0_OVF_InterruptHandler)(void);
	void (*TIMER0_OCMA_InterruptHandler)(void);
	void (*TIMER0_OCMB_InterruptHandler)(void);
}timer0_t;

/* ----------------------- Functions Declarations ----------------------- */
std_return_type_t timer0_Init(const timer0_t* _timer0_obj);
std_return_type_t timer0_DeInit(const timer0_t* _timer0_obj);
std_return_type_t timer0_SetPreload(const timer0_t* _timer0_obj);
std_return_type_t timer0_CompareMatchVal(const timer0_t* _timer0_obj);


#endif /* MCAL_TIMERS_TIMER0_TIMER0_H_ */
