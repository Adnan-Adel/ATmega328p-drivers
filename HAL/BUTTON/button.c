/*
 * button.c
 *
 *  Created on: Aug 24, 2023
 *      Author: Adnan
 */

#include "button.h"



/* ----------------------- Functions Definitions ----------------------- */
std_return_type_t button_init(const btn_t* _btn_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(NULL == _btn_obj)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		ret_val= gpio_pin_set_direction(_btn_obj->btn_port, _btn_obj->btn_pin, INPUT);
		if(_btn_obj->btn_connection_state == BTN_STATE_INT_PULL_UP)
		{
			ret_val= gpio_pin_connect_pullup(_btn_obj->btn_port, _btn_obj->btn_pin);
		}
	}
	return ret_val;
}

std_return_type_t button_read_state(const btn_t* _btn_obj, uint8_t* _state)
{
	std_return_type_t ret_val= RET_NOK;
		if(NULL == _btn_obj)
		{
			ret_val= NULL_PTR;
		}
		else
		{
			uint8_t _value;
			ret_val= gpio_pin_get_value(_btn_obj->btn_port, _btn_obj->btn_pin, &_value);
			if((_btn_obj->btn_connection_state == BTN_STATE_EXT_PULL_UP) || (_btn_obj->btn_connection_state == BTN_STATE_INT_PULL_UP))
			{
				if(_value == 0)
				{
					*_state= BTN_PRESSED;
				}
				else if(_value == 1)
				{
					*_state= BTN_RELEASED;
				}
			}
			else if(_btn_obj->btn_connection_state == BTN_STATE_EXT_PULL_DOWN)
			{
				if(_value == 0)
				{
					*_state= BTN_RELEASED;
				}
				else if(_value == 1)
				{
					*_state= BTN_PRESSED;
				}
			}
		}
		return ret_val;
}
