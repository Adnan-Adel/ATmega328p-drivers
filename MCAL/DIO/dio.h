/*
 * dio.h
 *
 * Created: 2/12/2023 1:24:58 PM
 *  Author: Adnan
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Utilities/Registers.h"

typedef enum
{
	LOW= 0,
	HIGH
}DIO_Value;

typedef enum
{
	INPUT= 0,
	OUTPUT
}DIO_Direction;

typedef enum
{
	PORTB_INDEX= 0,
	PORTC_INDEX,
	PORTD_INDEX
}DIO_PORT_ID;

typedef enum
{
	pin0= 0,
	pin1,
	pin2,
	pin3,
	pin4,
	pin5,
	pin6,
	pin7
}DIO_PIN_ID;

/* --------------------------------------- DIO FUNCTIONS PROTOTYPES --------------------------------------- */
void dio_pin_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Direction direction);

void dio_pin_write_value(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value value);

void dio_pin_read_value(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value *value);

void dio_pin_toggle_value(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);

#endif /* DIO_H_ */