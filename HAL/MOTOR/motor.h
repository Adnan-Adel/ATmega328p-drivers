/*
 * motor.h
 *
 * Created: 2/24/2023 4:41:19 PM
 *  Author: LAP TECH
 */ 


#ifndef MOTOR_H_
#define MOTOR_H_
#include "../../MCAL/DIO/dio.h"

#define MOTOR_PORT				PORTB_INDEX

#define MOTOR_A_LEFT_PIN		pin0
#define MOTOR_A_RIGHT_PIN		pin1
#define MOTOR_A_ENABLE			pin4

#define MOTOR_B_LEFT_PIN		pin2
#define MOTOR_B_RIGHT_PIN		pin3
#define MOTOR_B_ENABLE			pin5

void motor_init(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number,DIO_PORT_ID port_en, DIO_PIN_ID pin_enable_Number);
void motor_move_CW(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number);
void motor_move_CCW(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number);
void motor_stop(DIO_PORT_ID port1, DIO_PIN_ID pin1_Number,DIO_PORT_ID port2, DIO_PIN_ID pin2_Number);


#endif /* MOTOR_H_ */