/*
 * exti.c
 *
 *  Created on: Sep 2, 2023
 *      Author: Adnan
 */

#include "ext_interrupt.h"


static void (*INT0_InterruptHandler)(void)= NULL;
static void (*INT1_InterruptHandler)(void)= NULL;

/* --------------------------- Helper Functions Declarations --------------------------- */
static std_return_type_t Interrupt_INTx_Pin_Init(uint8_t ext_intx_src);
static std_return_type_t Interrupt_INTx_SetInterruptHandler(uint8_t ext_intx_src, void (*EXT_INTx_InterruptHandler)(void));


/* ----------------------- Functions Definitions ----------------------- */
std_return_type_t Interrupt_INTx_init(uint8_t ext_intx_src, uint8_t ext_intx_edge, void (*EXT_INTx_InterruptHandler)(void))
{
	std_return_type_t ret_val= RET_NOK;

	/* Disable External Interrupt */
	EXTI_InterruptDisable(ext_intx_src);

	/* Configure External Interrupt I/O pi */
	ret_val= Interrupt_INTx_Pin_Init(ext_intx_src);

	/* Configure External Interrupt Edge */
	ret_val= Interrupt_INTx_Edge_init(ext_intx_src, ext_intx_edge);

	/* Configure Default Interrupt CallBack */
	ret_val= Interrupt_INTx_SetInterruptHandler(ext_intx_src, EXT_INTx_InterruptHandler);

	/* Enable External Interrupt */
	INTERRUPT_GlobalInterruptEnable();
	EXTI_InterruptEnable(ext_intx_src);

	return ret_val;
}

std_return_type_t Interrupt_INTx_Edge_init(uint8_t ext_intx_src, uint8_t ext_intx_edge)
{
	switch(ext_intx_edge)
	{
		case EXTI_RISING_EDGE:
			if(ext_intx_src == EXTI_INT0)
			{
				EXTERNAL_IN0_RisingEdgeSet();
			}
			else if(ext_intx_src == EXTI_INT1)
			{
				EXTERNAL_IN1_RisingEdgeSet();
			}
		break;
		case EXTI_FALLING_EDGE:
			if(ext_intx_src == EXTI_INT0)
			{
				EXTERNAL_IN0_FallingEdgeSet();
			}
			else if(ext_intx_src == EXTI_INT1)
			{
				EXTERNAL_IN1_FallingEdgeSet();
			}
		break;
	}

	return RET_OK;
}

/* --------------------------- Helper Functions Definitions --------------------------- */
static std_return_type_t Interrupt_INTx_Pin_Init(uint8_t ext_intx_src)
{
	std_return_type_t ret_val= RET_NOK;

	if(ext_intx_src == EXTI_INT0)
	{
		ret_val= gpio_pin_set_direction(PORTD_INDEX, PIN2, INPUT);
	}
	else if(ext_intx_src == EXTI_INT1)
	{
		ret_val= gpio_pin_set_direction(PORTD_INDEX, PIN3, INPUT);
	}

	return ret_val;
}

static std_return_type_t Interrupt_INTx_SetInterruptHandler(uint8_t ext_intx_src, void (*EXT_INTx_InterruptHandler)(void))
{

	if(ext_intx_src == EXTI_INT0)
	{
		INT0_InterruptHandler= EXT_INTx_InterruptHandler;
		return RET_OK;
	}
	else if(ext_intx_src == EXTI_INT1)
	{
		INT1_InterruptHandler= EXT_INTx_InterruptHandler;
		return RET_OK;
	}
	else
	{
		return RET_NOK;
	}
}


/* --------------------------- ISR --------------------------- */
void __vector_1(void)   __attribute__((signal));
void __vector_1(void)
{
	if(INT0_InterruptHandler != NULL)
	{
		/* Clear Flag */
		EXT_INT0_InterruptFlagClear();

		/* Call Function */
		INT0_InterruptHandler();
	}
}

void __vector_2(void)   __attribute__((signal));
void __vector_2(void)
{
	if(INT1_InterruptHandler != NULL)
	{
		/* Clear Flag */
		EXT_INT1_InterruptFlagClear();

		/* Call Function */
		INT1_InterruptHandler();
	}
}
