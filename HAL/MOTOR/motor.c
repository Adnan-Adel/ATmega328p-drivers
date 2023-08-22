/*
 * motor.c
 *
 * Created: 2/24/2023 4:41:11 PM
 *  Author: LAP TECH
 */ 
#include "motor.h"

void motor_init(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number,DIO_PORT_ID port_en, DIO_PIN_ID pin_enable_Number)
{
	dio_pin_init(port1,pin1_Number,OUTPUT);
	dio_pin_init(port2,pin2_Number,OUTPUT);
	dio_pin_init(port_en,pin_enable_Number,OUTPUT);
	dio_pin_write_value(port_en,pin_enable_Number,HIGH);
}

void motor_move_CW(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number)
{
	dio_pin_write_value(port1,pin1_Number,HIGH);
	dio_pin_write_value(port2,pin2_Number,LOW);
}

void motor_move_CCW(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number)
{
	dio_pin_write_value(port1,pin1_Number,LOW);
	dio_pin_write_value(port2,pin2_Number,HIGH);
}

void motor_stop(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number)
{
	dio_pin_write_value(port1,pin1_Number,LOW);
	dio_pin_write_value(port2,pin2_Number,LOW);
}