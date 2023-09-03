#include "HAL/LED/hal_led.h"
#include "HAL/BUTTON/button.h"
#include "HAL/7SEG/seg.h"
#include "HAL/DC_MOTOR/dc_motor.h"
#include "HAL/KEYPAD/keypad.h"
#include "HAL/LCD/chr_lcd.h"
#include "MCAL/EXTI/ext_interrupt.h"

void Interrupt_Handler(void);

std_return_type_t ret;



btn_t btn1={
		.btn_port= PORTD_INDEX,
		.btn_pin= PIN2,
		.btn_connection_state= BTN_STATE_EXT_PULL_DOWN
};

seg_t seg1={
		.seg_mode= SEG_COM_ANODE,
		.seg_pins[0]._port= PORTB_INDEX,
		.seg_pins[0]._pin= PIN0,
		.seg_pins[1]._port= PORTB_INDEX,
		.seg_pins[1]._pin= PIN1,
		.seg_pins[2]._port= PORTB_INDEX,
		.seg_pins[2]._pin= PIN2,
		.seg_pins[3]._port= PORTB_INDEX,
		.seg_pins[3]._pin= PIN3,
		.seg_pins[4]._port= PORTB_INDEX,
		.seg_pins[4]._pin= PIN4,
		.seg_pins[5]._port= PORTB_INDEX,
		.seg_pins[5]._pin= PIN5,
		.seg_pins[6]._port= PORTB_INDEX,
		.seg_pins[6]._pin= PIN6,
		.seg_pins[7]._port= PORTB_INDEX,
		.seg_pins[7]._pin= PIN7,
};

dc_motor_t dc_motor1={
		.in1_port= PORTC_INDEX,
		.in1_pin= PIN0,
		.in2_port= PORTC_INDEX,
		.in2_pin= PIN1
};

keypad_t keypad1={
		.rows_port[0]= PORTC_INDEX,
		.rows_pins[0]= PIN0,
		.rows_port[1]= PORTC_INDEX,
		.rows_pins[1]= PIN1,
		.rows_port[2]= PORTC_INDEX,
		.rows_pins[2]= PIN2,
		.rows_port[3]= PORTC_INDEX,
		.rows_pins[3]= PIN3,

		.columns_port[0]= PORTD_INDEX,
		.columns_pins[0]= PIN1,
		.columns_port[1]= PORTD_INDEX,
		.columns_pins[1]= PIN2,
		.columns_port[2]= PORTD_INDEX,
		.columns_pins[2]= PIN3,
		.columns_port[3]= PORTD_INDEX,
		.columns_pins[3]= PIN4

};

chr_lcd_8bit_t lcd1={
		.lcd_rs_port= PORTB_INDEX,
		.lcd_rs_pin= PIN0,
		.lcd_en_port= PORTB_INDEX,
		.lcd_en_pin= PIN1,
		.lcd_data_port[0]= PORTB_INDEX,
		.lcd_data_pin[0]= PIN2,
		.lcd_data_port[1]= PORTB_INDEX,
		.lcd_data_pin[1]= PIN3,
		.lcd_data_port[2]= PORTB_INDEX,
		.lcd_data_pin[2]= PIN4,
		.lcd_data_port[3]= PORTB_INDEX,
		.lcd_data_pin[3]= PIN5,
		.lcd_data_port[4]= PORTB_INDEX,
		.lcd_data_pin[4]= PIN6,
		.lcd_data_port[5]= PORTB_INDEX,
		.lcd_data_pin[5]= PIN7,
		.lcd_data_port[6]= PORTC_INDEX,
		.lcd_data_pin[6]= PIN0,
		.lcd_data_port[7]= PORTC_INDEX,
		.lcd_data_pin[7]= PIN1,
};

chr_lcd_4bit_t lcd2={
		.lcd_rs_port= PORTD_INDEX,
		.lcd_rs_pin= PIN0,
		.lcd_en_port= PORTD_INDEX,
		.lcd_en_pin= PIN1,
		.lcd_data_port[0]= PORTD_INDEX,
		.lcd_data_pin[0]= PIN2,
		.lcd_data_port[1]= PORTD_INDEX,
		.lcd_data_pin[1]= PIN3,
		.lcd_data_port[2]= PORTD_INDEX,
		.lcd_data_pin[2]= PIN4,
		.lcd_data_port[3]= PORTD_INDEX,
		.lcd_data_pin[3]= PIN5,
};

uint8_t btn_val;
uint8_t k_val;

int main(void)
{
	ret= led_init(PORTB_INDEX, PIN2);
	ret= Interrupt_INTx_init(EXTI_INT0, EXTI_RISING_EDGE, Interrupt_Handler);
	while(1)
	{


	}
	return 0;
}

void Interrupt_Handler(void)
{
	ret= led_toggle(PORTB_INDEX, PIN2);
}
