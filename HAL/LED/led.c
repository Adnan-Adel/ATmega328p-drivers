/*
 * led.c
 *
 * Created: 3/16/2023 11:04:52 PM
 *  Author: LAP TECH
 */ 
#include "led.h"

void led_init(char port, char pin)
{
		dio_pin_init(port, pin, OUTPUT);
}

void led_turn_on(char port, char pin)
{
	dio_pin_write_value(port, pin, HIGH);
}

void led_turn_off(char port, char pin)
{
	dio_pin_write_value(port, pin, LOW);
}