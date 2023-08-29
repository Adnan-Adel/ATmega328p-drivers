/*
 * hal_led.h
 *
 *  Created on: Aug 23, 2023
 *      Author: Adnan
 */

#ifndef HAL_LED_HAL_LED_H_
#define HAL_LED_HAL_LED_H_

/* ------------------------------- Includes ------------------------------- */
#include "../../MCAL/GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */
#define ACTIVE_LOW			0
#define ACTIVE_HIGH			1

/* ------------------------------- Functions Declarations ------------------------------- */

/**
 * @brief initialize the pin (make the pin output).
 *
 * @param _led_port: 		Port index (@ref gpio_port_index_t)
 * @param _led_pin:  		Pin number (@ref gpio_pin_index_t)
 *
 * @return: @ref led_error_state_t
 */
std_return_type_t led_init(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin);

/**
 * @brief turn on the led depending on led state.
 *
 * @param _led_port: 		Port index (@ref gpio_port_index_t)
 * @param _led_pin:  		Pin number (@ref gpio_pin_index_t)
 * @param led_state 		ACTIVE_HIGH or ACTIVE_LOW
 *
 * @return: @ref led_error_state_t
 */
std_return_type_t led_turn_on(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin, uint8_t led_state);

/**
 * @brief turn off the led depending on led state.
 *
 * @param _led_port: 		Port index (@ref gpio_port_index_t)
 * @param _led_pin:  		Pin number (@ref gpio_pin_index_t)
 * @param led_state 		ACTIVE_HIGH or ACTIVE_LOW
 *
 * @return: @ref led_error_state_t
 */
std_return_type_t led_turn_off(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin, uint8_t led_state);

/**
 * @brief toggles the logic on led.
 *
 * @param _led_port: 		Port index (@ref gpio_port_index_t)
 * @param _led_pin:  		Pin number (@ref gpio_pin_index_t)
 *
 * @return: @ref led_error_state_t
 */
std_return_type_t led_toggle(gpio_port_index_t _led_port, gpio_pin_index_t _led_pin);

#endif /* HAL_LED_HAL_LED_H_ */
