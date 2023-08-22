/*
 * lcd.h
 *
 * Created: 5/3/2023 5:25:14 PM
 *  Author: Adnan
 */ 


#ifndef LCD_H_
#define LCD_H_
#include "../../MCAL/DIO/dio.h"
#include <stdio.h>
#include <string.h>
#define F_CPU	16000000
#include <util/delay.h>

#define LCD_Data_Dir					DDRD
#define LCD_Data_Out					PORTD
#define LCD_Ctrl_Dir					DDRB
#define LCD_Ctrl_Out					PORTB

#define LCD_4BIT_D7						pin4
#define LCD_4BIT_D6						pin5
#define LCD_4BIT_D5						pin6
#define LCD_4BIT_D4						pin7

#define LCD_4BIT_DATA_PORT				PORTD_INDEX
#define LCD_4BIT_CTRL_PORT				PORTC_INDEX

#define RS								pin0
#define E								pin1

#define _LCD_CLEAR                      0X01
#define _LCD_RETURN_HOME                0X02
#define _LCD_ENTRY_MODE                 0X06
#define _LCD_CURSOR_OFF_DISPLAY_ON      0X0C
#define _LCD_CURSOR_OFF_DISPLAY_OFF     0X08
#define _LCD_CURSOR_ON_BLINK_ON         0X0F
#define _LCD_CURSOR_ON_BLINK_OFF        0X0E
#define _LCD_DISPLAY_SHIFT_RIGHT        0X1C
#define _LCD_DISPLAY_SHIFT_LEFT         0X18
#define _LCD_8BIT_MODE_2_LINE           0X38
#define _LCD_4BIT_MODE_2_LINE           0X28
#define _LCD_CGRAM_START                0X40
#define _LCD_DDRAM_START                0X80

#define ROW1						    1
#define ROW2							2
#define ROW3							3
#define ROW4							4

void lcd_8bit_initialize();
void lcd_8bit_send_command(uint8_t data);
void lcd_8bit_send_char_data(uint8_t data);
void lcd_8bit_send_string(uint8_t *str);
void lcd_8bit_send_string_pos(uint8_t row, uint8_t col, uint8_t *str);
void lcd_8bit_convert_int_to_string(uint32_t value, uint8_t *str);
void convert_uint16_to_string(uint16 value, uint8_t *str);
void lcd_8bit_clearscreen();
void lcd_8bit_display_binary(uint8_t num);
void lcd_8bit_display_hex(uint8_t num);

void lcd_4bit_initialize();
void lcd_4bit_send_command(uint8_t command);
void lcd_4bit_send_char_data(uint8_t data);
void lcd_4bit_send_string(uint8_t *str);
void lcd_4bit_send_string_pos(uint8_t row, uint8_t col, uint8_t *str);

#endif /* LCD_H_ */