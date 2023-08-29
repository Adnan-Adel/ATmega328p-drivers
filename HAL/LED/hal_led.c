#include "hal_led.h"

std_return_type_t led_init(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin)
{
	std_return_type_t ret_val= RET_NOK;

	ret_val= gpio_pin_set_direction(_led_port, _led_pin, OUTPUT);

	return ret_val;
}

std_return_type_t led_turn_on(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin, uint8_t led_state)
{
	std_return_type_t ret_val= RET_NOK;

	if(ACTIVE_LOW == led_state)
	{
		ret_val= gpio_pin_set_value(_led_port, _led_pin, LOW);
	}
	else if(ACTIVE_HIGH == led_state)
	{
		ret_val= gpio_pin_set_value(_led_port, _led_pin, HIGH);
	}

	return ret_val;
}

std_return_type_t led_turn_off(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin, uint8_t led_state)
{
	std_return_type_t ret_val= RET_NOK;

	if(ACTIVE_LOW == led_state)
	{
		ret_val= gpio_pin_set_value(_led_port, _led_pin, HIGH);
	}
	else if(ACTIVE_HIGH == led_state)
	{
		ret_val= gpio_pin_set_value(_led_port, _led_pin, LOW);
	}

	return ret_val;
}

std_return_type_t led_toggle(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin)
{
	std_return_type_t ret_val= RET_NOK;

	ret_val= gpio_pin_toggle(_led_port, _led_pin);

	return ret_val;
}
