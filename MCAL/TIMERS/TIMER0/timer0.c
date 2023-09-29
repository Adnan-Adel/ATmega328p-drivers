/*
 * timer0.c
 *
 *  Created on: Sep 17, 2023
 *      Author: Adnan
 */

#include "timer0.h"

static void (*TIMER0_OVF_DefaultInterruptHandler)(void)= NULL;
static void (*TIMER0_OCMA_DefaultInterruptHandler)(void)= NULL;
static void (*TIMER0_OCMB_DefaultInterruptHandler)(void)= NULL;

/* --------------------------- Helper Functions Declarations --------------------------- */
static std_return_type_t timer0_Set_Waveform_Gen_Mode(const timer0_t* _timer0_obj);
static std_return_type_t timer0_Configuer_clk_src(const timer0_t* _timer0_obj);

/* ----------------------- Functions Definitions ----------------------- */

std_return_type_t timer0_Init(const timer0_t* _timer0_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_timer0_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		/* Disable TIMER0 */
		//TIMER0_MODULE_DISABLE();

		/* Configure Waveform Generation Mode */
		ret_val= timer0_Set_Waveform_Gen_Mode(_timer0_obj);

		/* Configure Clock Source */
		timer0_Configuer_clk_src(_timer0_obj);

		/* Enable Interrupt */
		if(_timer0_obj->Timer0_Waveform_Generation_Mode == NORMAL)
		{
			TIMER0_OVF_INTERRUPT_ENABLE();
		}
		else if(_timer0_obj->Timer0_Waveform_Generation_Mode == CTC)
		{
			TIMER0_OCMA_INTERRUPT_ENABLE();
		}

		/* Set Callback Function */
		TIMER0_OVF_DefaultInterruptHandler= _timer0_obj->TIMER0_OVF_InterruptHandler;
		TIMER0_OCMA_DefaultInterruptHandler= _timer0_obj->TIMER0_OVF_InterruptHandler;
		TIMER0_OCMB_DefaultInterruptHandler= _timer0_obj->TIMER0_OVF_InterruptHandler;

		/* Set Preload Value */
		ret_val= timer0_SetPreload(_timer0_obj);

		/* Enable TIMER0 */
		TIMER0_MODULE_ENABLE();
	}

	return ret_val;
}

std_return_type_t timer0_DeInit(const timer0_t* _timer0_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_timer0_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		/* Disable TIMER0 */
		TIMER0_MODULE_DISABLE();

		/* Disable Interrupt */
		if(_timer0_obj->Timer0_Waveform_Generation_Mode == NORMAL)
		{
			TIMER0_OVF_INTERRUPT_DISABLE();
		}
		else if(_timer0_obj->Timer0_Waveform_Generation_Mode == CTC)
		{
			TIMER0_OCMA_INTERRUPT_DISABLE();
		}

		ret_val= RET_OK;
	}

	return ret_val;
}

std_return_type_t timer0_SetPreload(const timer0_t* _timer0_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_timer0_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		TIMER0_TCNT0= _timer0_obj->Timer0_Preload_value;
		ret_val= RET_OK;
	}

	return ret_val;
}

std_return_type_t timer0_CompareMatchVal(const timer0_t* _timer0_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_timer0_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		if(_timer0_obj->Timer0_CMReg == CM_OCR0A)
		{
			TIMER0_OCR0A= _timer0_obj->Timer0_CM_Value;
		}
		else if(_timer0_obj->Timer0_CMReg == CM_OCR0B)
		{
			TIMER0_OCR0B= _timer0_obj->Timer0_CM_Value;
		}

		ret_val= RET_OK;
	}

	return ret_val;
}

/* --------------------------- Helper Functions Definitions --------------------------- */
std_return_type_t timer0_Set_Waveform_Gen_Mode(const timer0_t* _timer0_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_timer0_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		TIMER0_TCCR0A &= 0xFC;
		TIMER0_TCCR0B &= 0xFE;

		TIMER0_TCCR0A |= ((_timer0_obj->Timer0_Waveform_Generation_Mode) & 0x01);
		TIMER0_TCCR0A |= ((_timer0_obj->Timer0_Waveform_Generation_Mode) & 0x02);
		TIMER0_TCCR0B |= (((_timer0_obj->Timer0_Waveform_Generation_Mode) & 0x04) << 1);

		ret_val= RET_OK;
	}

	return ret_val;
}

static std_return_type_t timer0_Configuer_clk_src(const timer0_t* _timer0_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_timer0_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		TIMER0_TCCR0A &= 0xFC;
		TIMER0_TCCR0B &= 0xFE;

		TIMER0_TCCR0B |= ((_timer0_obj->Timer0_Clock_Source) & 0x07);

		ret_val= RET_OK;
	}

	return ret_val;
}


/* --------------------------- ISR --------------------------- */
void __vector_16 (void) __attribute__((signal));					// TIMER0 OVF
void __vector_16 (void)
{
	if(TIMER0_OVF_DefaultInterruptHandler != NULL)
	{
		/* Clear Flag */
		TIMER0_OVF_INTERRUPT_FLAG_CLEAR();

		/* Call Function */
		TIMER0_OVF_DefaultInterruptHandler();
	}
}

void __vector_15 (void) __attribute__((signal));					// TIMER0 COMPB
void __vector_15 (void)
{
	if(TIMER0_OCMB_DefaultInterruptHandler != NULL)
	{
		/* Clear Flag */
		TIMER0_OCMB_INTERRUPT_FLAG_CLEAR();

		/* Call Function */
		TIMER0_OCMB_DefaultInterruptHandler();
	}
}

void __vector_14 (void) __attribute__((signal));					// TIMER0 COMPA
void __vector_14 (void)
{
	if(TIMER0_OCMA_DefaultInterruptHandler != NULL)
	{
		/* Clear Flag */
		TIMER0_OCMA_INTERRUPT_FLAG_CLEAR();

		/* Call Function */
		TIMER0_OCMA_DefaultInterruptHandler();
	}
}
