/*
 * usart.c
 *
 *  Created on: Sep 28, 2023
 *      Author: Adnan
 */
#include "usart.h"

/* --------------------------- Helper Functions Declarations --------------------------- */
static std_return_type_t USART_Set_Mode(const usart_t* _usart_obj);
static std_return_type_t USART_Set_Parity_Mode(const usart_t* _usart_obj);
static std_return_type_t USART_Set_DataBits(const usart_t* _usart_obj);

/* ----------------------- Functions Definitions ----------------------- */
std_return_type_t USART_ASYNC_Init(const usart_t* _usart_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		/* Disable USART */
		USART_Transmit_Disable();
		USART_Receive_Disable();

		ret_val= gpio_pin_set_direction(PORTD_INDEX, PIN0, INPUT);
		ret_val= gpio_pin_set_direction(PORTD_INDEX, PIN1, OUTPUT);

		/* Configure Mode */
		ret_val= USART_Set_Mode(_usart_obj);

		/* Configure Frame (Data Bits, Parity Bit, Stop Bit) */
		ret_val= USART_Set_Parity_Mode(_usart_obj);
		ret_val= USART_Set_DataBits(_usart_obj);
		if(_usart_obj->usart_stop_bits == ONE_STOP_BIT_CFG)
		{
			USART_SET_ONE_STOP_BIT();
		}
		else if(_usart_obj->usart_stop_bits == TWO_STOP_BITS_CFG)
		{
			USART_SET_TWO_STOP_BITS();
		}

		/* Configure Baud Rate */
		/*uint16 temp_Baudrate= (uint16)((F_CPU / _usart_obj->usart_baudrate) - 1);
		UBRR0H= (uint8_t)(temp_Baudrate >> 8);
		UBRR0L= (uint8_t)temp_Baudrate;*/
		UBRR0L= 103;


		/* Enable USART */
		if(_usart_obj->usart_transmission_mode == USART_Tx)
		{
			USART_Transmit_Enable();
		}
		else if(_usart_obj->usart_transmission_mode == USART_Rx)
		{
			USART_Receive_Enable();
		}
	}
	return ret_val;
}

std_return_type_t USART_ASYNC_DeInit(const usart_t* _usart_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		/* Disable USART */
		USART_Transmit_Disable();
		USART_Receive_Disable();
	}
	return ret_val;
}

std_return_type_t USART_Asych_Send_Char(const usart_t* _usart_obj, uint8_t data)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		while(!GET_BIT(UCSR0A,TXC0));
		UDR0= data;
	}
	return ret_val;
}

std_return_type_t USART_Asych_Read_Char(const usart_t* _usart_obj, uint8_t* rec_data)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		while(!GET_BIT(UCSR0A,RXC0));
		*rec_data= UDR0;
	}
	return ret_val;
}

std_return_type_t USART_Asych_Send_String(const usart_t* _usart_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{

	}
	return ret_val;
}

std_return_type_t USART_Asych_Read_String(const usart_t* _usart_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{

	}
	return ret_val;
}

/* --------------------------- Helper Functions Definitions --------------------------- */
static std_return_type_t USART_Set_Mode(const usart_t* _usart_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		if(_usart_obj->usart_mode == USART_MODE_ASYNCHRONOUS)
		{
			CLEAR_BIT(UCSR0C,UMSEL00);
			CLEAR_BIT(UCSR0C,UMSEL01);
		}
		else if(_usart_obj->usart_mode == USART_MODE_SYNCHRONOUS)
		{
			SET_BIT(UCSR0C,UMSEL00);
			CLEAR_BIT(UCSR0C,UMSEL01);
		}
		else if(_usart_obj->usart_mode == USART_MODE_MASTER_SPI)
		{
			SET_BIT(UCSR0C,UMSEL00);
			SET_BIT(UCSR0C,UMSEL01);
		}
		ret_val= RET_OK;
	}
	return ret_val;
}

static std_return_type_t USART_Set_Parity_Mode(const usart_t* _usart_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		if(_usart_obj->usart_parity == PARITY_DISABLED)
		{
			CLEAR_BIT(UCSR0C,UPM00);
			CLEAR_BIT(UCSR0C,UPM01);
		}
		else if(_usart_obj->usart_mode == PARITY_ENABLED_EVEN)
		{
			CLEAR_BIT(UCSR0C,UPM00);
			SET_BIT(UCSR0C,UPM01);
		}
		else if(_usart_obj->usart_mode == PARITY_ENABLED_ODD)
		{
			SET_BIT(UCSR0C,UPM00);
			SET_BIT(UCSR0C,UPM01);
		}
		ret_val= RET_OK;
	}
	return ret_val;
}

static std_return_type_t USART_Set_DataBits(const usart_t* _usart_obj)
{
	std_return_type_t ret_val= RET_NOK;
	if(_usart_obj == NULL)
	{
		ret_val= NULL_PTR;
	}
	else
	{
		if(_usart_obj->usart_data_bits == DATA_BITS_5)
		{
			CLEAR_BIT(UCSR0C,UCSZ00);
			CLEAR_BIT(UCSR0C,UCSZ01);
			CLEAR_BIT(UCSR0B,UCSZ02);
		}
		else if(_usart_obj->usart_data_bits == DATA_BITS_6)
		{
			SET_BIT(UCSR0C,UCSZ00);
			CLEAR_BIT(UCSR0C,UCSZ01);
			CLEAR_BIT(UCSR0B,UCSZ02);
		}
		else if(_usart_obj->usart_data_bits == DATA_BITS_7)
		{
			CLEAR_BIT(UCSR0C,UCSZ00);
			SET_BIT(UCSR0C,UCSZ01);
			CLEAR_BIT(UCSR0B,UCSZ02);
		}
		else if(_usart_obj->usart_data_bits == DATA_BITS_8)
		{
			SET_BIT(UCSR0C,UCSZ00);
			SET_BIT(UCSR0C,UCSZ01);
			CLEAR_BIT(UCSR0B,UCSZ02);
		}
		else if(_usart_obj->usart_data_bits == DATA_BITS_9)
		{
			SET_BIT(UCSR0C,UCSZ00);
			SET_BIT(UCSR0C,UCSZ01);
			SET_BIT(UCSR0B,UCSZ02);
		}
		ret_val= RET_OK;
	}
	return ret_val;
}
