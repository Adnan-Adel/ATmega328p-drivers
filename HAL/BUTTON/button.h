/*
 * button.h
 *
 * Created: 12/7/2022 9:29:55 PM
 *  Author: Adnan
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO/dio.h"	

#define BUTTON_PORT				PORTC_INDEX

#define FORWARD_BUTTON_PIN	    pin0
#define LEFT_BUTTON_PIN			pin1
#define RIGHT_BUTTON_PIN		pin2
#define BACKWARD_BUTTON_PIN		pin3
#define STOP_BUTTON_PIN		    pin4

#define BUTTON_NOT_PRESSED 0
#define BUTTON_PRESSED     1

void BUTTON_init(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber);

void BUTTON_read(DIO_PORT_ID portNumber, DIO_PIN_ID pinNumber, DIO_Value *value);




#endif /* BUTTON_H_ */