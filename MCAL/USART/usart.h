/*
 * usart.h
 *
 *  Created on: Sep 28, 2023
 *      Author: Adnan
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

/* ------------------------------- Includes ------------------------------- */
#include "../GPIO/mcal_gpio.h"
#include "../EXTI/ext_interrupt.h"

/* ------------------------------- Macros Declarations ------------------------------- */
#define USART_Tx										0
#define USART_Rx										1

#define FRAME_ERROR_DETECTED							0
#define DATA_OVERRUN_ERROR_DETECTED						1
#define PARITY_ERROR_DETECTED							2

#define NORMAL_SPEED									0
#define DOUBLE_SPEED									1

#define USART_MODE_ASYNCHRONOUS							0
#define USART_MODE_SYNCHRONOUS							1
#define USART_MODE_MASTER_SPI							3

#define PARITY_DISABLED									0
#define PARITY_ENABLED_EVEN								2
#define PARITY_ENABLED_ODD								3

#define DATA_BITS_5										0
#define DATA_BITS_6										1
#define DATA_BITS_7										2
#define DATA_BITS_8										3
#define DATA_BITS_9										7

#define ONE_STOP_BIT_CFG								1
#define TWO_STOP_BITS_CFG								2


/* ------------------------------- Macro Functions ------------------------------- */
#define USART_Receive_Enable()							(SET_BIT(UCSR0B,RXEN0))
#define USART_Receive_Disable()							(CLEAR_BIT(UCSR0B,RXEN0))

#define USART_Transmit_Enable()							(SET_BIT(UCSR0B,TXEN0))
#define USART_Transmit_Disable()						(CLEAR_BIT(UCSR0B,TXEN0))

#define USART_DoubleTransmissionSpeed()					(SET_BIT(UCSR0A,U2X0))
#define USART_NormalTransmissionSpeed()					(CLEAR_BIT(UCSR0A,U2X0))
#define SYNCH_Enable_MultiProcessorMode()				(SET_BIT(UCSR0A,MPCM0))

#define USART_RxComplete_InterruptEnable()				(SET_BIT(UCSR0B,RXCIE0))
#define USART_TxComplete_InterruptEnable()				(SET_BIT(UCSR0B,TXCIE0))
#define USART_DREmpty_InterruptEnable()					(SET_BIT(UCSR0B,UDRIE0))

#define USART_RxComplete_InterruptDisable()				(CLEAR_BIT(UCSR0B,RXCIE0))
#define USART_TxComplete_InterruptDisable()				(CLEAR_BIT(UCSR0B,TXCIE0))
#define USART_DREmpty_InterruptDisable()				(CLEAR_BIT(UCSR0B,UDRIE0))

#define USART_SET_ONE_STOP_BIT()						(CLEAR_BIT(UCSR0C,USBS0))
#define USART_SET_TWO_STOP_BITS()						(SET_BIT(UCSR0C,USBS0))

#define SET_Tx_RISING_Rx_FALLING()						(CLEAR_BIT(UCSR0C,UCPOL0))
#define SET_Tx_FALLING_Rx_RISING()						(SET_BIT(UCSR0C,UCPOL0))

/* ------------------------------- data types declarations ------------------------------- */
typedef struct
{
	uint8_t usart_mode;
	uint8_t usart_transmission_mode;
	uint8_t usart_speed;
	uint8_t usart_parity;
	uint8_t usart_data_bits;
	uint8_t usart_stop_bits;
	uint8_t usart_error_status;
	uint16 usart_baudrate;

	void (*EUSART_TxDefaultInterruptHandler)(void);
	void (*EUSART_RxDefaultInterruptHandler)(void);
	void (*EUSART_FramingErrorHandler)(void);
	void (*EUSART_DataOverrunErrorHandler)(void);
	void (*EUSART_ParityErrorHandler)(void);
}usart_t;


/* ----------------------- Functions Declarations ----------------------- */
std_return_type_t USART_ASYNC_Init(const usart_t* _usart_obj);
std_return_type_t USART_ASYNC_DeInit(const usart_t* _usart_obj);

std_return_type_t USART_Asych_Send_Char(const usart_t* _usart_obj, uint8_t data);
std_return_type_t USART_Asych_Read_Char(const usart_t* _usart_obj, uint8_t* rec_data);

std_return_type_t USART_Asych_Send_String(const usart_t* _usart_obj);
std_return_type_t USART_Asych_Read_String(const usart_t* _usart_obj);

#endif /* MCAL_USART_USART_H_ */
