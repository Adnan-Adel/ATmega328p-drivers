/*
 * eeprom.h
 *
 *  Created on: Sep 13, 2023
 *      Author: Adnan
 */

#ifndef HAL_EEPROM_EEPROM_H_
#define HAL_EEPROM_EEPROM_H_

/* ------------------------------- Includes ------------------------------- */
#include "../../MCAL/GPIO/mcal_gpio.h"
#include "../../MCAL/EXTI/ext_interrupt.h"

/* ------------------------------- Macros Declarations ------------------------------- */
// EECR bits
#define EEPM1						5
#define EEPM0						4
#define EERIE						3
#define EEMPE						2
#define EEPE						1
#define EERE						0


// EEPROM Mode
#define EEPROM_ERASE_WRITE			0		// Programming Time= 3.4ms
#define EEPROM_ERASE_ONLY			1		// Programming Time= 1.8ms
#define EEPROM_WRITE_ONLY			2		// Programming Time= 1.8ms

/* ------------------------------- Functions Like Macro ------------------------------- */
#define EEPROM_INTERRUPT_ENABLE()		SET_BIT(EEPROM_EECR, EERIE)
#define EEPROM_INTERRUPT_DISABLE()		CLEAR_BIT(EEPROM_EECR, EERIE)

/* ------------------------------- Functions Declarations ------------------------------- */
std_return_type_t eeprom_Write_Byte(uint16 byte_address, uint8_t byte_data);
std_return_type_t eeprom_Read_Byte(uint16 byte_address, uint8_t* byte_data);


#endif /* HAL_EEPROM_EEPROM_H_ */
