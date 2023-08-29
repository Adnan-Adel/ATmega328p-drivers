/*
 * dc_motor.h
 *
 *  Created on: Aug 25, 2023
 *      Author: Adnan
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

/* ------------------------------- Includes ------------------------------- */
#include "../../MCAL/GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */


/* ------------------------------- data types declarations ------------------------------- */
typedef struct
{
	gpio_port_index_t in1_port;
	gpio_pin_index_t in1_pin;
	gpio_port_index_t in2_port;
	gpio_pin_index_t in2_pin;
	gpio_port_index_t en_port;
	gpio_pin_index_t en_pin;
}dc_motor_t;

/* ------------------------------- Functions Declarations ------------------------------- */
std_return_type_t dc_motor_init(const dc_motor_t* _dc_motor_obj);
std_return_type_t dc_motor_move_CW(const dc_motor_t* _dc_motor_obj);
std_return_type_t dc_motor_move_CCW(const dc_motor_t* _dc_motor_obj);
std_return_type_t dc_motor_stop(const dc_motor_t* _dc_motor_obj);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
