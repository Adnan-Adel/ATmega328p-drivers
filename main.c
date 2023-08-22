/*
 * ATmega328P-Drivers.c
 *
 * Created: 7/4/2023 11:38:00 PM
 * Author : Adnan
 */ 

#include "APP/app.h"

void Default_InterruptHandler(void);

int main(void)
{
    led_init(PORTB_INDEX, pin1);
    BUTTON_init(PORTD_INDEX, pin2);
    Interrupt_INTx_Init(INTERRUPT_EXTERNAL_INT0, INTERRUPT_RISING_EDGE, Default_InterruptHandler);
	
}

void Default_InterruptHandler(void)
{
	led_turn_on(PORTB_INDEX, pin1);
}