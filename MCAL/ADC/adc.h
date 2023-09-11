/*
 * adc.h
 *
 *  Created on: Sep 10, 2023
 *      Author: Adnan
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_

/* ------------------------------- Includes ------------------------------- */
#include "../GPIO/mcal_gpio.h"

/* ------------------------------- Macros Declarations ------------------------------- */
// ADMUX Pins
#define REFS1									7
#define REFS0									6
#define ADLAR									5
#define MUX3									3
#define MUX2									2
#define MUX1									1
#define MUX0									0

// ADCSRA Pins
#define ADEN									7
#define ADSC									6
#define ADATE									5
#define ADIF									4
#define ADIE									3
#define ADPS2									2
#define ADPS1									1
#define ADPS0									0


#define ADC_VOLTAGE_REF_AREF					0x00
#define ADC_VOLTAGE_REF_AVCC					0x01
#define ADC_VOLTAGE_REF_INTERNAL_1_1			0x11

#define ADC_RESULT_RIGHT_ADJUSTMENT				0
#define ADC_RESULT_LEFT_ADJUSTMENT				1

#define ADC_CHANNEL_ADC0						0
#define ADC_CHANNEL_ADC1						1
#define ADC_CHANNEL_ADC2						2
#define ADC_CHANNEL_ADC3						3
#define ADC_CHANNEL_ADC4						4
#define ADC_CHANNEL_ADC5						5

#define ADC_PRESCALER_DIV_BY_2					0
#define ADC_PRESCALER_DIV_BY_4					2
#define ADC_PRESCALER_DIV_BY_8					3
#define ADC_PRESCALER_DIV_BY_16					4
#define ADC_PRESCALER_DIV_BY_32					5
#define ADC_PRESCALER_DIV_BY_64					6
#define ADC_PRESCALER_DIV_BY_128				7

#define ADC_FREE_RUNNING_MODE					0
#define ADC_ANALOG_COMPARATOR					1
#define ADC_EXT_INTERRUPT_REQ0					2
#define ADC_TIMER0_COMPARE_MATCH_A				3
#define ADC_TIMER0_OVF							4
#define ADC_TIMER1_COMPARE_MATCH_B				5
#define ADC_TIMER1_OVF							6
#define ADC_TIMER1_CAPTURE_EVENT				7

/* ------------------------------- Macro Functions ------------------------------- */
#define ADC_ENABLE()							SET_BIT(ADC_ADCSRA, ADEN)
#define ADC_DISABLE()							CLEAR_BIT(ADC_ADCSRA, ADEN)
#define ADC_START_CONVERSION()					SET_BIT(ADC_ADCSRA, ADSC)
#define ADC_INTERRUPT_FLAG_CLEAR()				SET_BIT(ADC_ADCSRA, ADIF)
#define ADC_INTERRUPT_Enable()					SET_BIT(ADC_ADCSRA, ADIE)				// ADC Conversion Complete Interrupt is activated
#define ADC_AUTO_TRIGGER_ENABLE()				SET_BIT(ADC_ADCSRA, ADATE)

/* ------------------------------- data types declarations ------------------------------- */
typedef struct
{
    void (*ADC_InterruptHandler)(void);
	uint8_t adc_channel;
	uint8_t voltage_ref;
	uint8_t result_format;
	uint8_t prescaler;
}adc_t;

/* ----------------------- Functions Declarations ----------------------- */
std_return_type_t ADC_init(const adc_t* _adc_obj);
std_return_type_t ADC_Set_Voltage_Ref(uint8_t v_ref);
std_return_type_t ADC_Set_Result_Adjustment(uint8_t result_adjust);
std_return_type_t ADC_Channel_Select(uint8_t _channel);
std_return_type_t ADC_Set_Prescaler(uint8_t _prescaler);
std_return_type_t ADC_Set_Auto_Trig_Src(uint8_t _src);

std_return_type_t ADC_IsConversionDone( uint8_t *conversion_status);
std_return_type_t ADC_GetConversionResult( uint16 *conversion_result, uint8_t _adjust);
std_return_type_t ADC_Blocking_GetConversion(const adc_t* _adc_obj, uint16 *conversion_result);
std_return_type_t ADC_Interrupt_GetConversion(const adc_t* _adc_obj, void (*ADC_InterruptCallBack) (void));

#endif /* MCAL_ADC_ADC_H_ */
