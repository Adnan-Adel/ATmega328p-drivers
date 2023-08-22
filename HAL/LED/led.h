/*
 * led.h
 *
 * Created: 3/16/2023 11:05:03 PM
 *  Author: LAP TECH
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO/dio.h"

#define LED_PORT	PORTD_INDEX
#define LED1_PIN	pin0
#define LED2_PIN	pin1

void led_init(char port, char pin);
void led_turn_on(char port, char pin);
void led_turn_off(char port, char pin);



#endif /* LED_H_ */