/*
 * app.c
 *
 * Created: 3/20/2023 2:40:11 PM
 *  Author: Adnan
 */ 
#include "app.h"


void app_init(void)
{
	/*lcd_8bit_initialize();
	ADC_Init(ADC_CONVERSION_CLOCK_FOSC_DIV_2, ADC_VOLTAGE_REF_AREF, ADC_RESULT_RIGHT_ADJUSTMENT);*/
	
	
}

void app_start(void)
{
	/*uint16 lm35_res_1, lm35_res_1_Celsius_mv = 0;
	uint8_t lm35_res_1_txt[7];
	lcd_8bit_send_command(_LCD_8BIT_MODE_2_LINE);
	lcd_8bit_send_string("VValue: ");
	while(1)
	{
		ADC_Blocking_GetConversion(ADC_CHANNEL_AN2, &lm35_res_1, ADC_RESULT_RIGHT_ADJUSTMENT);
		
		lm35_res_1_Celsius_mv = lm35_res_1 * 4.88f; // 5000(mv) / 1024(10-Bit) => 4.88
		
		lm35_res_1_Celsius_mv /= 10; // The sensitivity of LM35 is 10 mV/degree Celsius
		lcd_8bit_convert_int_to_string(lm35_res_1_Celsius_mv, lm35_res_1_txt);
		//_delay_us(1000);
		//lcd_8bit_send_command(_LCD_CLEAR);
		lcd_8bit_send_string_pos(1, 9, lm35_res_1_txt);
	}*/
	
	/*uint16 lm35_res_1, lm35_res_1_Celsius_mv = 0;
	uint8_t lm35_res_1_txt[7];
	lcd_8bit_send_string((uint8_t *)" Temp: ");
	while(1){
		ADC_Blocking_GetConversion(ADC_CHANNEL_AN2, &lm35_res_1, ADC_RESULT_RIGHT_ADJUSTMENT);
		
		lm35_res_1_Celsius_mv = lm35_res_1 * 4.88f;		// 5000(mv) / 1024(10-Bit) => 4.88 
		
		lm35_res_1_Celsius_mv /= 10;					// The sensitivity of LM35 is 10 mV/degree Celsius 
		
		convert_uint16_to_string(lm35_res_1_Celsius_mv, lm35_res_1_txt);
		
		lcd_8bit_send_string_pos(1, 8, lm35_res_1_txt);
		_delay_ms(1);
	}*/
	
}

