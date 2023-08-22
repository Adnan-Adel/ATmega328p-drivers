/*
 * uart.h
 *
 * Created: 7/12/2023 6:14:05 PM
 *  Author: Adnan
 */ 


#ifndef UART_H_
#define UART_H_

#include "../DIO/dio.h"

/* ----------------------------------------- Macro Functions ----------------------------------------- */
#define UART_NORMAL_SPEED()			CLEAR_BIT(UCSRA, 1);
#define UART_DOUBLE_SPEED()			SET_BIT(UCSRA, 1);

/* -------------------------------------- Functions Declarations -------------------------------------- */
void UART_Init();
void UART_TransmitChar(uint8_t data);
uint8_t UART_ReceiveChar();
void UART_ReceiveStr(char* str);
void UART_TransmitStr(char* str);


#endif /* UART_H_ */