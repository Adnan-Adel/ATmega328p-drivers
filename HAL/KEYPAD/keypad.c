/*
 * keypad.c
 *
 *  Created on: Aug 27, 2023
 *      Author: Adnan
 */

#include "keypad.h"

static const uint8_t keypad_values[KEYPAD_ROWS][KEYPAD_COLUMNS]={
    {'7','8','9','/'},
    {'4','5','6','*'},
    {'1','2','3','-'},
    {'#','0','=','+'}
};

std_return_type_t keypad_init(const keypad_t* _keypad_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(NULL == _keypad_obj)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		uint8_t index_i= 0;
		/* Initializing Rows Pins */
		for(index_i= 0; index_i < KEYPAD_ROWS; index_i++)
		{
			ret_val= gpio_pin_set_direction(_keypad_obj->rows_port[index_i], _keypad_obj->rows_pins[index_i], OUTPUT);
		}
		/* Initializing Columns Pins */
		for(index_i= 0; index_i < KEYPAD_ROWS; index_i++)
		{
			ret_val= gpio_pin_set_direction(_keypad_obj->columns_port[index_i], _keypad_obj->columns_pins[index_i], INPUT);
		}
	}
	return ret_val;
}

std_return_type_t keypad_get_pressed_value(const keypad_t* _keypad_obj, uint8_t* keypad_value)
{
	std_return_type_t ret_val= RET_NOK;
	if(NULL == _keypad_obj)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		uint8_t rows_index= 0;
		uint8_t columns_index= 0;
		uint8_t index_i= 0;
		uint8_t column_value;

		for(rows_index= 0; rows_index < KEYPAD_ROWS; rows_index++)
		{
			/* Disable all rows (To make sure that all rows are disactive) */
			for(index_i= 0; index_i < KEYPAD_ROWS; index_i++)
			{
				ret_val= gpio_pin_set_value(_keypad_obj->rows_port[index_i], _keypad_obj->rows_pins[index_i], LOW);
			}
			/* then enabling the specified row */
			ret_val= gpio_pin_set_value(_keypad_obj->rows_port[rows_index], _keypad_obj->rows_pins[rows_index], HIGH);
			_delay_ms(5);

			/* Read value on columns */
			for(columns_index= 0; columns_index < KEYPAD_COLUMNS; columns_index++)
			{
				ret_val= gpio_pin_get_value(_keypad_obj->columns_port[columns_index], _keypad_obj->columns_pins[columns_index], &column_value);
				if(HIGH == column_value)
				{
					*keypad_value= keypad_values[rows_index][columns_index];
				}
			}
		}
	}
	return ret_val;
}
