/*
 * ext_interrupt.c
 *
 * Created: 7/7/2023 3:06:15 PM
 *  Author: Adnan
 */ 
#include "ext_interrupt.h"
#include <avr/interrupt.h>

static void (*INT0_InterruptHandler)(void)= NULL;
static void (*INT1_InterruptHandler)(void)= NULL;

/* --------------------------- Helper Functions Declarations --------------------------- */
static void Interrupt_INTx_Enable(Interrupt_INTx_src _src);
static void Interrupt_INTx_Disable(Interrupt_INTx_src _src);
static void Interrupt_INTx_Clear_Flag(Interrupt_INTx_src _src);
static void Interrupt_INTx_Edge_Init(Interrupt_INTx_edge _edge, Interrupt_INTx_src _src);
static void Interrupt_INTx_Pin_Init(Interrupt_INTx_src _src);
static void Interrupt_INTx_SetInterruptHandler(Interrupt_INTx_src _src, void (*EXT_INTx_InterruptHandler)(void));

/* --------------------------- Functions Definitions --------------------------- */
void Interrupt_INTx_Init(Interrupt_INTx_src _src, Interrupt_INTx_edge _edge, void (*EXT_INTx_InterruptHandler)(void))
{
	/* Configure External Interrupt Edge */
	Interrupt_INTx_Edge_Init(_edge, _src);
	
	/* Configure External Interrupt I/O pi */
	Interrupt_INTx_Pin_Init(_src);

	/* Configure Default Interrupt CallBack */
	Interrupt_INTx_SetInterruptHandler(_src, EXT_INTx_InterruptHandler);
	
	/* Enable External Interrupt */
	Interrupt_INTx_Enable(_src);
}

/* --------------------------- Helper Functions Definitions --------------------------- */
static void Interrupt_INTx_Enable(Interrupt_INTx_src _src)
{
	switch(_src)
	{
		case INTERRUPT_EXTERNAL_INT0:
			INTERRUPT_GlobalInterruptEnable();
			EXT_INT0_InterruptEnable();
			break;
		case INTERRUPT_EXTERNAL_INT1:
			INTERRUPT_GlobalInterruptEnable();
			EXT_INT1_InterruptEnable();
			break;
	}
}

static void Interrupt_INTx_Disable(Interrupt_INTx_src _src)
{
	switch(_src)
	{
		case INTERRUPT_EXTERNAL_INT0:
		EXT_INT0_InterruptDisable();
		break;
		case INTERRUPT_EXTERNAL_INT1:
		EXT_INT1_InterruptDisable();
		break;
	}
}

static void Interrupt_INTx_Clear_Flag(Interrupt_INTx_src _src)
{
	switch(_src)
	{
		case INTERRUPT_EXTERNAL_INT0:
		EXT_INT0_InterruptFlagClear();
		break;
		case INTERRUPT_EXTERNAL_INT1:
		EXT_INT1_InterruptFlagClear();
		break;
	}
}

static void Interrupt_INTx_Edge_Init(Interrupt_INTx_edge _edge, Interrupt_INTx_src _src)
{
	switch(_edge)
	{
		case INTERRUPT_FALLING_EDGE:
			if(_src == INTERRUPT_EXTERNAL_INT0)
			{
				EXTERNAL_IN0_FallingEdgeSet();
			}
			else if(_src == INTERRUPT_EXTERNAL_INT1)
			{
				EXTERNAL_IN1_FallingEdgeSet();
			}
			break;
		case INTERRUPT_RISING_EDGE:
			if(_src == INTERRUPT_EXTERNAL_INT0)
			{
				EXTERNAL_IN0_RisingEdgeSet();
			}
			else if(_src == INTERRUPT_EXTERNAL_INT1)
			{
				EXTERNAL_IN1_RisingEdgeSet();
			}
			break;
	}
}

static void Interrupt_INTx_Pin_Init(Interrupt_INTx_src _src)
{
	if(_src == INTERRUPT_EXTERNAL_INT0)
	{
		dio_pin_init(PORTD_INDEX, pin2, INPUT);
	}
	else if(_src == INTERRUPT_EXTERNAL_INT1)
	{
		dio_pin_init(PORTD_INDEX, pin3, INPUT);
	}
}

static void Interrupt_INTx_SetInterruptHandler(Interrupt_INTx_src _src, void (*EXT_INTx_InterruptHandler)(void))
{
	switch(_src)
	{
		case INTERRUPT_EXTERNAL_INT0:
		INT0_InterruptHandler= EXT_INTx_InterruptHandler;
		break;
		case INTERRUPT_EXTERNAL_INT1:
		INT1_InterruptHandler= EXT_INTx_InterruptHandler;
		break;
	}
}



void INT0_ISR(INT0_vect)
{
	// The INT0 External Interrupt Occurred (must be cleared)
	EXT_INT0_InterruptFlagClear();
	
	// Callback Function gets called every time this ISR executes
	if(INT0_InterruptHandler != NULL)
	{
		INT0_InterruptHandler();
	}
}

void INT1_ISR(INT1_vect)
{
	// The INT1 External Interrupt Occurred (must be cleared) 
	EXT_INT1_InterruptFlagClear();
	
	// Callback Function gets called every time this ISR executes 
	if(INT1_InterruptHandler != NULL)
	{
		INT1_InterruptHandler();
	}
}