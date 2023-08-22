/*
 * uart.c
 *
 * Created: 7/12/2023 6:13:54 PM
 *  Author: Adnan
 */ 
#include "uart.h"

void UART_Init()
{
	//Configure Baud Rate
	UBRRL= 103;
	
	//Configure Normal Speed
	CLEAR_BIT(UCSRA, 1);
	
	//Configure Parity -> Even Parity
	SET_BIT(UCSRC, 5);
	CLEAR_BIT(UCSRC, 4);
	
	//Configure data bits
	SET_BIT(UCSRC, 1);
	SET_BIT(UCSRC, 2);
	CLEAR_BIT(UCSRB, 2);
	
	//Mode: Asynchronous
	//Enable RX
	SET_BIT(UCSRB, 4);
	
	//Enable TX
	SET_BIT(UCSRB, 3);
	
}

void UART_TransmitChar(uint8_t data)
{
	while(!(READ_BIT(UCSRA, 5)));
		UDR= data;
}

uint8_t UART_ReceiveChar()
{
	while(!(READ_BIT(UCSRA, 7)));
	return UDR;
}

void UART_ReceiveStr(char* str)
{
	uint8_t index_i= 0;
	uint8_t received_dat;
	do{
		received_dat= UART_ReceiveChar();
		str[index_i]= received_dat;
		index_i++;
	}while(received_dat != '\r');
	str[index_i]= '\0';
}

void UART_TransmitStr(char* str)
{
	uint8_t index_i= 0;
	
	while(str[index_i] != '\0')
	{
		while(!(READ_BIT(UCSRA,5)));
		UDR = str[index_i];
		index_i++;
	}
}