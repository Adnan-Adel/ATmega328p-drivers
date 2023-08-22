/*
 * dio.c
 *
 * Created: 2/12/2023 1:24:38 PM
 *  Author: Adnan
 */ 

#include "dio.h"

void dio_pin_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Direction direction)
{
	switch(portNumber)
	{
		case PORTB_INDEX:
			if( INPUT == direction)
			{
				CLEAR_BIT(DDRB, pinNumber);
			}
			else if(OUTPUT == direction)
			{
				SET_BIT(DDRB, pinNumber);
			}
		break;
		
		case PORTC_INDEX:
		if( INPUT == direction)
		{
			CLEAR_BIT(DDRC, pinNumber);
		}
		else if(OUTPUT == direction)
		{
			SET_BIT(DDRC, pinNumber);
		}
		break;
		
		case PORTD_INDEX:
		if( INPUT == direction)
		{
			CLEAR_BIT(DDRD, pinNumber);
		}
		else if(OUTPUT == direction)
		{
			SET_BIT(DDRD, pinNumber);
		}
		break;
	}
}

void dio_pin_write_value(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value value)
{
	switch(portNumber)
	{
		case PORTB_INDEX:
		if( LOW == value)
		{
			CLEAR_BIT(PORTB, pinNumber);
		}
		else if(HIGH == value)
		{
			SET_BIT(PORTB, pinNumber);
		}
		break;
		
		case PORTC_INDEX:
		if( LOW == value)
		{
			CLEAR_BIT(PORTC, pinNumber);
		}
		else if(HIGH == value)
		{
			SET_BIT(PORTC, pinNumber);
		}
		break;
		
		case PORTD_INDEX:
		if( LOW == value)
		{
			CLEAR_BIT(PORTD, pinNumber);
		}
		else if(HIGH == value)
		{
			SET_BIT(PORTD, pinNumber);
		}
		break;
	}	
}

void dio_pin_read_value(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value *value)
{
	switch(portNumber)
	{
		case PORTB_INDEX:
			*value= READ_BIT(PINB, pinNumber);
		break;
		
		case PORTC_INDEX:
			*value= READ_BIT(PINC, pinNumber);
		break;
		
		case PORTD_INDEX:
			*value= READ_BIT(PIND, pinNumber);
		break;
	}
}

void dio_pin_toggle_value(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber)
{
	switch(portNumber)
	{
		case PORTB_INDEX:
			TOGGLE_BIT(PORTB, pinNumber);
		break;
		
		case PORTC_INDEX:
			TOGGLE_BIT(PORTC, pinNumber);
		break;
		
		case PORTD_INDEX:
			TOGGLE_BIT(PORTD, pinNumber);
		break;
	}	
}