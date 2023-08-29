/*
 * button.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Adnan
 */

#ifndef HAL_BUTTON_BUTTON_H_
#define HAL_BUTTON_BUTTON_H_

/* ------------------------------- Includes ------------------------------- */
#include "../../MCAL/GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */
// Button Pressing State
#define BTN_RELEASED					0
#define BTN_PRESSED						1


// Button Connection State
#define BTN_STATE_EXT_PULL_DOWN			0
#define BTN_STATE_EXT_PULL_UP			1
#define BTN_STATE_INT_PULL_UP			2


/* ------------------------------- data types declarations ------------------------------- */
typedef struct
{
	gpio_port_index_t btn_port;
	gpio_pin_index_t btn_pin;
	uint8_t btn_connection_state;
}btn_t;


/* ----------------------- Functions Declarations ----------------------- */
std_return_type_t button_init(const btn_t* _btn_obj);
std_return_type_t button_read_state(const btn_t* _btn_obj, uint8_t* _state);

#endif /* HAL_BUTTON_BUTTON_H_ */
