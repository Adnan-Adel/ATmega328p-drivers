/*
 * adc.c
 *
 * Created: 7/10/2023 9:22:21 PM
 *  Author: Adnan
 */ 
#include "adc.h"

void ADC_Init(adc_Prescaler_t _prescaler, adc_voltage_ref_t _vref, adc_result_adjustment_t _adjust)
{
	switch(_vref)
	{
		case ADC_VOLTAGE_REF_AREF:
			CLEAR_BIT(ADMUX, REFS0);
			CLEAR_BIT(ADMUX, REFS1);
			break;
		case ADC_VOLTAGE_REF_AVCC:
			SET_BIT(ADMUX, REFS0);
			CLEAR_BIT(ADMUX, REFS1);
			break;
		case ADC_VOLTAGE_REF_INTERNAL_11:
			SET_BIT(ADMUX, REFS0);
			SET_BIT(ADMUX, REFS1);
			break;
	}
	
	switch(_adjust)
	{
		case ADC_RESULT_RIGHT_ADJUSTMENT:
			CLEAR_BIT(ADMUX, ADLAR);
			break;
		case ADC_RESULT_LEFT_ADJUSTMENT:
			SET_BIT(ADMUX, ADLAR);
			break;
	}
	
	/*prescaler*/
	ADCSRA = ADCSRA & 0xf8;
	ADCSRA = ADCSRA | _prescaler;
	
	// Enable ADC
	SET_BIT(ADCSRA, ADEN);
}

void ADC_SelectChannel(adc_channel_select_t _channel)
{
	ADMUX =  ADMUX &  0xE0;
	ADMUX = ADMUX | _channel;
	
	// Make Channel INPUT
	switch(_channel)
	{
		case ADC_CHANNEL_AN0:  dio_pin_init(PORTC_INDEX, pin0, INPUT); break;
		case ADC_CHANNEL_AN1:  dio_pin_init(PORTC_INDEX, pin1, INPUT); break;
		case ADC_CHANNEL_AN2:  dio_pin_init(PORTC_INDEX, pin2, INPUT); break;
		case ADC_CHANNEL_AN3:  dio_pin_init(PORTC_INDEX, pin3, INPUT); break;
		case ADC_CHANNEL_AN4:  dio_pin_init(PORTC_INDEX, pin4, INPUT); break;
		case ADC_CHANNEL_AN5:  dio_pin_init(PORTC_INDEX, pin5, INPUT); break;
	}
}

void ADC_StartConversion()
{
	SET_BIT(ADCSRA, ADSC);
}

void ADC_IsConversionDone( uint8_t *conversion_status)
{
	*conversion_status= READ_BIT(ADCSRA, ADIF);		// 1 -> Conversion is done
													// 0 -> Conversion not done
}

void ADC_GetConversionResult( uint16 *conversion_result, adc_result_adjustment_t _adjust)
{
	if(ADC_RESULT_RIGHT_ADJUSTMENT == _adjust)
	{
		*conversion_result= (uint16)((ADCH << 8) + ADCL);
	}
	else if(ADC_RESULT_LEFT_ADJUSTMENT == _adjust)
	{
		*conversion_result= (uint16)(((ADCH << 8) + ADCL) >> 6);
	}
	else
	{
		*conversion_result= (uint16)((ADCH << 8) + ADCL);
	}
}

void ADC_Blocking_GetConversion(adc_channel_select_t _channel, uint16 *conversion_result, adc_result_adjustment_t _adjust)
{
	 /* Select A/D channel */
	 ADC_SelectChannel(_channel);
	 
	 /* Start Conversion */
	 ADC_StartConversion();
	 
	 /* Check if conversion is completed */
	 while(READ_BIT(ADCSRA,ADSC));
	 
	 ADC_GetConversionResult(conversion_result, _adjust);
}
