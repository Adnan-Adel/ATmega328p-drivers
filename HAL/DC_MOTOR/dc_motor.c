/*
 * dc_motor.c
 *
 *  Created on: Aug 25, 2023
 *      Author: Adnan
 */

#include "dc_motor.h"

std_return_type_t dc_motor_init(const dc_motor_t* _dc_motor_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(NULL == _dc_motor_obj)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		ret_val= gpio_pin_set_direction(_dc_motor_obj->in1_port, _dc_motor_obj->in1_pin, OUTPUT);
		ret_val= gpio_pin_set_direction(_dc_motor_obj->in2_port, _dc_motor_obj->in2_pin, OUTPUT);
		ret_val= gpio_pin_set_direction(_dc_motor_obj->en_port, _dc_motor_obj->en_pin, OUTPUT);
	}
	return ret_val;
}

std_return_type_t dc_motor_move_CW(const dc_motor_t* _dc_motor_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(NULL == _dc_motor_obj)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		ret_val= gpio_pin_set_value(_dc_motor_obj->in1_port, _dc_motor_obj->in1_pin, HIGH);
		ret_val= gpio_pin_set_value(_dc_motor_obj->in2_port, _dc_motor_obj->in2_pin, LOW);
	}
	return ret_val;
}

std_return_type_t dc_motor_move_CCW(const dc_motor_t* _dc_motor_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(NULL == _dc_motor_obj)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		ret_val= gpio_pin_set_value(_dc_motor_obj->in1_port, _dc_motor_obj->in1_pin, LOW);
		ret_val= gpio_pin_set_value(_dc_motor_obj->in2_port, _dc_motor_obj->in2_pin, HIGH);
	}
	return ret_val;
}

std_return_type_t dc_motor_stop(const dc_motor_t* _dc_motor_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(NULL == _dc_motor_obj)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		ret_val= gpio_pin_set_value(_dc_motor_obj->in1_port, _dc_motor_obj->in1_pin, LOW);
		ret_val= gpio_pin_set_value(_dc_motor_obj->in2_port, _dc_motor_obj->in2_pin, LOW);
	}
	return ret_val;
}
