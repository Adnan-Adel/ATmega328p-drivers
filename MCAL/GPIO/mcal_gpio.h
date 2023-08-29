/**
 * @file mcal_gpio.h
 * @brief Functions and data types declarations for GPIO pins and ports.
 *
 * @author Adnan Adel
 * @date 23/8/2023
 *
 */

#ifndef __MCAL_GPIO_H__
#define __MCAL_GPIO_H__

/* ------------------------------- Includes ------------------------------- */
#include "../../Utilities/Registers.h"

#include <util/delay.h>
/* ------------------------------- Macros Declarations ------------------------------- */
#define PUD		4	// The Pull-up disable bit in MCUCR-Reg

#define F_CPU	8000000UL

/* ------------------------------- data types declarations ------------------------------- */
typedef enum
{
	LOW,
	HIGH
}gpio_value_t;

typedef enum
{
	INPUT,
	OUTPUT
}gpio_direction_t;

typedef enum
{
	PORTB_INDEX,
	PORTC_INDEX,
	PORTD_INDEX
}gpio_port_index_t;

typedef enum
{
	PIN0,
	PIN1,
	PIN2,
	PIN3,
	PIN4,
	PIN5,
	PIN6,
	PIN7,
}gpio_pin_index_t;



/* ----------------------- Functions Declarations ----------------------- */

/**
 * @brief Initialize the direction of a pin in a port.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param _pin:  		Pin number (@ref gpio_pin_index_t)
 * @param _direction: 	Input or Output
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_pin_set_direction(gpio_port_index_t _port, gpio_pin_index_t _pin, gpio_direction_t _direction);

/**
 * @brief outputs a value on a specific pin.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param _pin:  		Pin number (@ref gpio_pin_index_t)
 * @param _value: 		High or Low
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_pin_set_value(gpio_port_index_t _port, gpio_pin_index_t _pin, gpio_value_t _value);

/**
 * @brief toggles value on a specific pin.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param _pin:  		Pin number (@ref gpio_pin_index_t)
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_pin_toggle(gpio_port_index_t _port, gpio_pin_index_t _pin);

/**
 * @brief Reads value on a specific pin and stores it in variable pointed to by pointer value.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param _pin:  		Pin number (@ref gpio_pin_index_t)
 * @param value: 		pointer to an uint8_t variable which will store pin's value
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_pin_get_value(gpio_port_index_t _port, gpio_pin_index_t _pin, uint8_t* value);

/**
 * @brief Connects internal pullup resistor to a pin.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param _pin:  		Pin number (@ref gpio_pin_index_t)
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_pin_connect_pullup(gpio_port_index_t _port, gpio_pin_index_t _pin);


/**
 * @brief Initialize the direction of a port.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param _direction: 	an uint8_t value between 0x00 and 0xFF
 * 						0x00 -> all pins on port will be input.
 * 						0xFF -> all pins on port will be output.
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_port_set_direction(gpio_port_index_t _port, uint8_t _direction);

/**
 * @brief outputs a value on pins of a port.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param _value: 		an uint8_t value between 0x00 and 0xFF
 * 						0x00 -> all pins on port will be Low.
 * 						0xFF -> all pins on port will be High.
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_port_set_value(gpio_port_index_t _port, uint8_t _value);

/**
 * @brief toggles value on every pin on a port.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_port_toggle(gpio_port_index_t _port);

/**
 * @brief Reads value on a specific port and stores it in variable pointed to by pointer value.
 *
 * @param _port: 		Port index (@ref gpio_port_index_t)
 * @param value: 		pointer to an uint8_t variable which will store pin's value
 *
 * @return: @ref gpio_error_state_t
 */
std_return_type_t gpio_port_get_value(gpio_port_index_t _port, uint8_t* value);

#endif
