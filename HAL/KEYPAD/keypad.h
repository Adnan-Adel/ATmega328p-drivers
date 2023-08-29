/*
 * keypad.h
 *
 *  Created on: Aug 27, 2023
 *      Author: Adnan
 */

#ifndef HAL_KEYPAD_KEYPAD_H_
#define HAL_KEYPAD_KEYPAD_H_

/* ------------------------------- Includes ------------------------------- */
#include "../../MCAL/GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */
#define KEYPAD_ROWS	    	4
#define KEYPAD_COLUMNS		4


/* ------------------------------- data types declarations ------------------------------- */
typedef struct
{
	gpio_port_index_t rows_port[KEYPAD_ROWS];
	gpio_pin_index_t rows_pins[KEYPAD_ROWS];
	gpio_port_index_t columns_port[KEYPAD_COLUMNS];
	gpio_pin_index_t columns_pins[KEYPAD_COLUMNS];
}keypad_t;

/* ------------------------------- Functions Declarations ------------------------------- */
std_return_type_t keypad_init(const keypad_t* _keypad_obj);

std_return_type_t keypad_get_pressed_value(const keypad_t* _keypad_obj, uint8_t* keypad_value);


#endif /* HAL_KEYPAD_KEYPAD_H_ */
