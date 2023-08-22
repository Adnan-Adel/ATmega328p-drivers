/*
 * app.h
 *
 * Created: 3/20/2023 2:40:19 PM
 *  Author: Adnan
 */ 


#ifndef APP_H_
#define APP_H_

#include "../HAL/MOTOR/motor.h"
#include "../HAL/BUTTON/button.h"
#include "../HAL/LED/led.h"
#include "../HAL/LCD/lcd.h"

#include "../MCAL/ADC/adc.h"
#include "../MCAL/INTERRUPT/ext_interrupt.h"
#include "../MCAL/UART/uart.h"

void app_init(void);

void app_start(void);

#endif /* APP_H_ */