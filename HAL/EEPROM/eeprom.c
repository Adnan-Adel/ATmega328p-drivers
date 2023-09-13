/*
 * eeprom.c
 *
 *  Created on: Sep 13, 2023
 *      Author: Adnan
 */

#include "eeprom.h"

std_return_type_t eeprom_Write_Byte(uint16 byte_address, uint8_t byte_data)
{
	/* Read Interrupt Status (Enabled or Disabled) */
	uint8_t Global_Interrupt_Status= GET_BIT(SREG,I);

	/* Wait for completion of previous write */
	while(GET_BIT(EEPROM_EECR, EEPE));

	/* Update Address Register */
	EEPROM_EEARH= (uint8_t)((byte_address >> 8) & 0x03);
	EEPROM_EEARL= (uint8_t)(byte_address & 0xFF);

	/* Update Data Register */
	EEPROM_EEDR= byte_data;

	/* Write logical one to EEMPE */
	SET_BIT(EEPROM_EECR, EEMPE);

	/* Start eeprom write by setting EEPE */
	SET_BIT(EEPROM_EECR, EEPE);

	/* Restore the Global Interrupt status */
	SREG |= (Global_Interrupt_Status << I);

	return RET_OK;
}

std_return_type_t eeprom_Read_Byte(uint16 byte_address, uint8_t* byte_data)
{
	/* Wait for completion of previous write */
	while(GET_BIT(EEPROM_EECR, EEPE));

	/* Update Address Register */
	EEPROM_EEARH= (uint8_t)((byte_address >> 8) & 0x03);
	EEPROM_EEARL= (uint8_t)(byte_address & 0xFF);

	/* Start eeprom read by writing EERE */
	SET_BIT(EEPROM_EECR, EERE);

	/* Read Data From EEPROM Data Register (EEDR) */
	*byte_data= EEPROM_EEDR;

	return RET_OK;
}
