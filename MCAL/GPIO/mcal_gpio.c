/**
 * @file mcal_gpio.c
 * @brief Functions definitions for GPIO pins and ports.
 *
 * @author Adnan Adel
 * @date 23/8/2023
 *
 */

#include "mcal_gpio.h"

/* ----------------------- Functions Definitions ----------------------- */

/* -------------------------------------- Pin Functions -------------------------------------- */
std_return_type_t gpio_pin_set_direction(gpio_port_index_t _port, gpio_pin_index_t _pin, gpio_direction_t _direction)
{
	std_return_type_t ret_val= RET_NOK;

	if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
	{
		ret_val= GPIO_PORT_INVALID;
	}
	else if((_pin > PIN7) || (_pin < PIN0))
	{
		ret_val= GPIO_PIN_INVALID;
	}
	else
	{
		if(INPUT == _direction)
		{
			switch(_port)
			{
				case PORTB_INDEX: CLEAR_BIT(GPIO_DDRB,_pin); break;
				case PORTC_INDEX: CLEAR_BIT(GPIO_DDRC,_pin); break;
				case PORTD_INDEX: CLEAR_BIT(GPIO_DDRD,_pin); break;
			}
			ret_val= RET_OK;
		}
		else if(OUTPUT == _direction)
		{
			switch(_port)
			{
				case PORTB_INDEX: SET_BIT(GPIO_DDRB,_pin); break;
				case PORTC_INDEX: SET_BIT(GPIO_DDRC,_pin); break;
				case PORTD_INDEX: SET_BIT(GPIO_DDRD,_pin); break;
			}
			ret_val= RET_OK;
		}
	}

	return ret_val;
}

std_return_type_t gpio_pin_set_value(gpio_port_index_t _port, gpio_pin_index_t _pin, gpio_value_t _value)
{
	std_return_type_t ret_val= RET_NOK;

	if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
	{
		ret_val= GPIO_PORT_INVALID;
	}
	else if((_pin > PIN7) || (_pin < PIN0))
	{
		ret_val= GPIO_PIN_INVALID;
	}
	else
	{
		if(LOW == _value)
		{
			switch(_port)
			{
				case PORTB_INDEX: CLEAR_BIT(GPIO_PORTB,_pin); break;
				case PORTC_INDEX: CLEAR_BIT(GPIO_PORTC,_pin); break;
				case PORTD_INDEX: CLEAR_BIT(GPIO_PORTD,_pin); break;
			}
			ret_val= RET_OK;
		}
		else if(HIGH == _value)
		{
			switch(_port)
			{
				case PORTB_INDEX: SET_BIT(GPIO_PORTB,_pin); break;
				case PORTC_INDEX: SET_BIT(GPIO_PORTC,_pin); break;
				case PORTD_INDEX: SET_BIT(GPIO_PORTD,_pin); break;
			}
			ret_val= RET_OK;
		}
	}

	return ret_val;
}

std_return_type_t gpio_pin_toggle(gpio_port_index_t _port, gpio_pin_index_t _pin)
{
	std_return_type_t ret_val= RET_NOK;

		if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
		{
			ret_val= GPIO_PORT_INVALID;
		}
		else if((_pin > PIN7) || (_pin < PIN0))
		{
			ret_val= GPIO_PIN_INVALID;
		}
		else
		{
			switch(_port)
			{
				case PORTB_INDEX: TOG_BIT(GPIO_PORTB,_pin); break;
				case PORTC_INDEX: TOG_BIT(GPIO_PORTC,_pin); break;
				case PORTD_INDEX: TOG_BIT(GPIO_PORTD,_pin); break;
			}
			ret_val= RET_OK;
		}

		return ret_val;
}

std_return_type_t gpio_pin_get_value(gpio_port_index_t _port, gpio_pin_index_t _pin, uint8_t* value)
{
	std_return_type_t ret_val= RET_NOK;

	if(NULL == value)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
		{
			ret_val= GPIO_PORT_INVALID;
		}
		else if((_pin > PIN7) || (_pin < PIN0))
		{
			ret_val= GPIO_PIN_INVALID;
		}
		else
		{
			switch(_port)
			{
				case PORTB_INDEX:
					*value= GET_BIT(GPIO_PINB,_pin);
					break;
				case PORTC_INDEX:
					*value= GET_BIT(GPIO_PINC,_pin);
					break;
				case PORTD_INDEX:
					*value= GET_BIT(GPIO_PIND,_pin);
					break;
			}
			ret_val= RET_OK;
		}
	}

	return ret_val;
}

std_return_type_t gpio_pin_connect_pullup(gpio_port_index_t _port, gpio_pin_index_t _pin)
{
	std_return_type_t ret_val= RET_NOK;

	if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
	{
		ret_val= GPIO_PORT_INVALID;
	}
	else if((_pin > PIN7) || (_pin < PIN0))
	{
		ret_val= GPIO_PIN_INVALID;
	}
	else
	{
		CLEAR_BIT(MCUCR,PUD);
		switch(_port)
		{
			case PORTB_INDEX:
				CLEAR_BIT(GPIO_DDRB,_pin);
				SET_BIT(GPIO_PORTB,_pin);
				break;
			case PORTC_INDEX:
				CLEAR_BIT(GPIO_DDRC,_pin);
				SET_BIT(GPIO_PORTC,_pin);
				break;
			case PORTD_INDEX:
				CLEAR_BIT(GPIO_DDRD,_pin);
				SET_BIT(GPIO_PORTD,_pin);
				break;
		}
		ret_val= RET_OK;
	}

	return ret_val;
}

/* -------------------------------------- PORT Functions -------------------------------------- */
std_return_type_t gpio_port_set_direction(gpio_port_index_t _port, uint8_t _direction)
{
	std_return_type_t ret_val= RET_NOK;

	if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
	{
		ret_val= GPIO_PORT_INVALID;
	}
	else
	{
		switch(_port)
		{
		case PORTB_INDEX:
			GPIO_DDRB= _direction;
			break;
		case PORTC_INDEX:
			GPIO_DDRC= _direction;
			break;
		case PORTD_INDEX:
			GPIO_DDRD= _direction;
			break;
		}
		ret_val= RET_OK;
	}

	return ret_val;
}

std_return_type_t gpio_port_set_value(gpio_port_index_t _port, uint8_t _value)
{
	std_return_type_t ret_val= RET_NOK;

	if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
	{
		ret_val= GPIO_PORT_INVALID;
	}
	else
	{
		switch(_port)
		{
		case PORTB_INDEX:
			GPIO_PORTB= _value;
			break;
		case PORTC_INDEX:
			GPIO_PORTC= _value;
			break;
		case PORTD_INDEX:
			GPIO_PORTD= _value;
			break;
		}
		ret_val= RET_OK;
	}

	return ret_val;
}

std_return_type_t gpio_port_toggle(gpio_port_index_t _port)
{
	std_return_type_t ret_val= RET_NOK;

	if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
	{
		ret_val= GPIO_PORT_INVALID;
	}
	else
	{
		switch(_port)
		{
		case PORTB_INDEX:
			GPIO_PORTB ^= 0xFF;
			break;
		case PORTC_INDEX:
			GPIO_PORTC ^= 0xFF;
			break;
		case PORTD_INDEX:
			GPIO_PORTD ^= 0xFF;
			break;
		}
		ret_val= RET_OK;
	}

	return ret_val;
}

std_return_type_t gpio_port_get_value(gpio_port_index_t _port, uint8_t* value)
{
	std_return_type_t ret_val= RET_NOK;

	if(NULL == value)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		if((_port > PORTD_INDEX) || (_port < PORTB_INDEX))
		{
			ret_val= GPIO_PORT_INVALID;
		}
		else
		{
			switch(_port)
			{
				case PORTB_INDEX:
					*value= GPIO_PINB;
					break;
				case PORTC_INDEX:
					*value= GPIO_PINC;
					break;
				case PORTD_INDEX:
					*value= GPIO_PIND;
					break;
			}
			ret_val= RET_OK;
		}
	}

	return ret_val;
}
