/*
 * seg.h
 *
 *  Created on: Aug 24, 2023
 *      Author: Adnan
 */

#ifndef HAL_SEG_HAL_SEG_H_
#define HAL_SEG_HAL_SEG_H_

/* ------------------------------- Includes ------------------------------- */
#include "../../MCAL/GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */
#define SEG_COM_CATHODE			0
#define SEG_COM_ANODE			1

/* ------------------------------- data types declarations ------------------------------- */
typedef struct
{
	gpio_port_index_t _port;
	gpio_pin_index_t _pin;
}seg_pin_t;

typedef struct
{
	uint8_t seg_mode;
	seg_pin_t seg_pins[8];
}seg_t;

/* ------------------------------- Functions Declarations ------------------------------- */
std_return_type_t seg_init(const seg_t* _seg_obj);
std_return_type_t seg_write_nnum(const seg_t* _seg_obj, uint8_t num);

#endif
