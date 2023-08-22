/*
 * lcd.c
 *
 * Created: 5/3/2023 5:25:06 PM
 *  Author: Adnan
 */ 
#include "lcd.h"
static void lcd_send_enable_signal();
static void lcd_8bit_set_cursor(uint8_t row, uint8_t col);
static void lcd_4bit_set_cursor(uint8_t row, uint8_t col);
static void lcd_send_4bit(uint8_t _data_command);
/* ----------------------------------- lcd_8bit_functions implementation ----------------------------------- */

void lcd_8bit_initialize()
{
	LCD_Data_Dir = 0xFF;
	LCD_Ctrl_Dir |= (1<<E) | (1<<RS);
	
	lcd_8bit_send_command(_LCD_8BIT_MODE_2_LINE);
	lcd_8bit_send_command(_LCD_CURSOR_OFF_DISPLAY_ON);
	lcd_8bit_send_command(_LCD_CLEAR);
}

void lcd_8bit_send_command(uint8_t data)
{
	CLEAR_BIT(LCD_Ctrl_Out,RS);
	
	LCD_Data_Out = data;
	
	lcd_send_enable_signal();
}

void lcd_8bit_send_char_data(uint8_t data)
{
	SET_BIT(LCD_Ctrl_Out,RS);
	
	LCD_Data_Out = data;
	
	lcd_send_enable_signal();
}

void lcd_8bit_send_string(uint8_t *str)
{
	while(*str != '\0')
	{
		lcd_8bit_send_char_data(*str);
		str++;
	}
}

void lcd_8bit_send_string_pos(uint8_t row, uint8_t col, uint8_t *str)
{
	lcd_8bit_set_cursor(row,col);
	lcd_8bit_send_string(str);
}

void lcd_8bit_convert_int_to_string(uint32_t value, uint8_t *str)
{
	memset(str, '\0', 11);
	sprintf(str, "%i", value);
	//lcd_8bit_send_string(str);
}

void convert_uint16_to_string(uint16 value, uint8_t *str)
{
	uint8_t Temp_String[6] = {0};
	uint8_t DataCounter = 0;

	memset(str, ' ', 5);
	str[5] = '\0';
	sprintf((char *)Temp_String, "%i", value);
	while(Temp_String[DataCounter] != '\0')
	{
		str[DataCounter] = Temp_String[DataCounter];
		DataCounter++;
	}
}

void lcd_8bit_clearscreen()
{
	lcd_8bit_send_command(_LCD_CLEAR);
}

void lcd_8bit_display_binary(uint8_t num)
{
	uint8_t bin[9], rem;
	uint8_t index_i = 0;
	bin[8] = '\0';
	for(index_i = 0; index_i < 8; index_i++)
	{
		rem = num % 2;
		num /= 2;
		bin[7 - index_i] = rem + '0';
	}
	lcd_8bit_send_string(bin);
}

void lcd_8bit_display_hex(uint8_t num)
{
	uint8_t hex[3];
	sprintf(hex, "%02X", num);
	lcd_8bit_send_string(hex);
}

/* ----------------------------------- lcd_4bit_functions implementation ----------------------------------- */

void lcd_4bit_initialize()
{
	uint8_t index_i= 0;
	dio_pin_init(LCD_4BIT_CTRL_PORT, RS, OUTPUT);
	dio_pin_init(LCD_4BIT_CTRL_PORT, E, OUTPUT);
	
	for(index_i=0; index_i < 4; index_i++)
	{
		dio_pin_init(LCD_4BIT_DATA_PORT, index_i, OUTPUT);
	}
	
	_delay_ms(20);
	lcd_4bit_send_command(_LCD_8BIT_MODE_2_LINE);
	_delay_ms(5);
	lcd_4bit_send_command(_LCD_8BIT_MODE_2_LINE);
	_delay_us(120);
	lcd_4bit_send_command(_LCD_8BIT_MODE_2_LINE);
	
	lcd_4bit_send_command(_LCD_CLEAR);
	lcd_4bit_send_command(_LCD_RETURN_HOME);
	lcd_4bit_send_command(_LCD_ENTRY_MODE);
	lcd_4bit_send_command(_LCD_CURSOR_OFF_DISPLAY_ON);
	lcd_4bit_send_command(_LCD_4BIT_MODE_2_LINE);
	//lcd_4bit_send_command(_LCD_CURSOR_ON_BLINK_ON);
	
}

void lcd_4bit_send_command(uint8_t command)
{
	dio_pin_write_value(LCD_4BIT_CTRL_PORT, RS, LOW);
	
	lcd_send_4bit(command >> 4);                   // Send 4 HIGH bits first
	
	// Sending Hight to Low transition on Enable Signal
	lcd_send_enable_signal();
	
	lcd_send_4bit(command);                       // Send 4 LOW bits
	
	// Sending Hight to Low transition on Enable Signal
	lcd_send_enable_signal();
}

void lcd_4bit_send_char_data(uint8_t data)
{
	dio_pin_write_value(LCD_4BIT_CTRL_PORT, RS, HIGH);
	
	lcd_send_4bit(data >> 4);                   // Send 4 HIGH bits first
	
	// Sending Hight to Low transition on Enable Signal
	lcd_send_enable_signal();
	
	lcd_send_4bit(data);                       // Send 4 LOW bits
	
	// Sending Hight to Low transition on Enable Signal
	lcd_send_enable_signal();
}

void lcd_4bit_send_string(uint8_t *str)
{
	while(*str)
	{
		lcd_4bit_send_char_data(*str);
		str++;
	}
}

void lcd_4bit_send_string_pos(uint8_t row, uint8_t col, uint8_t *str)
{
	lcd_4bit_set_cursor(row,col);
	lcd_4bit_send_string(str);
}


/* ----------------------------------- Helper Functions -----------------------------------*/

static void lcd_send_enable_signal()
{
	SET_BIT(LCD_Ctrl_Out,E);
	_delay_us(5);
	
	CLEAR_BIT(LCD_Ctrl_Out,E);
}

static void lcd_8bit_set_cursor(uint8_t row, uint8_t col)
{
	col--;
	switch (row)
	{
		case ROW1:
		lcd_8bit_send_command(0x80 + col);
		break;
		
		case ROW2:
		lcd_8bit_send_command(0xc0 + col);
		break;
		
		case ROW3:
		lcd_8bit_send_command(0x94 + col);
		break;
		
		case ROW4:
		lcd_8bit_send_command(0xd4 + col);
		break;
	}
	
}

static void lcd_4bit_set_cursor(uint8_t row, uint8_t col)
{
	col--;
	switch (row)
	{
		case ROW1:
		lcd_4bit_send_command(0x80 + col);
		break;
		
		case ROW2:
		lcd_4bit_send_command(0xc0 + col);
		break;
		
		case ROW3:
		lcd_4bit_send_command(0x94 + col);
		break;
		
		case ROW4:
		lcd_4bit_send_command(0xd4 + col);
		break;
	}
	
}

static void lcd_send_4bit(uint8_t _data_command)
{
	dio_pin_write_value(LCD_4BIT_DATA_PORT, LCD_4BIT_D4, ((_data_command >> 0) & 0x01));
	dio_pin_write_value(LCD_4BIT_DATA_PORT, LCD_4BIT_D5, ((_data_command >> 1) & 0x01));
	dio_pin_write_value(LCD_4BIT_DATA_PORT, LCD_4BIT_D6, ((_data_command >> 2) & 0x01));
	dio_pin_write_value(LCD_4BIT_DATA_PORT, LCD_4BIT_D7, ((_data_command >> 3) & 0x01));
}