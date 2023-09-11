/*
 * adc.c
 *
 *  Created on: Sep 10, 2023
 *      Author: Adnan
 */

#include "adc.h"

static void (*ADC_DefaultInterruptHandler)(void)= NULL;

/* --------------------------- Helper Functions Declarations --------------------------- */
static std_return_type_t ADC_Set_InterruptHandler(const adc_t* _adc_obj, void (*ADC_InterruptHandler)(void));

/* ----------------------- Functions Definitions ----------------------- */
std_return_type_t ADC_init(const adc_t* _adc_obj)
{
	std_return_type_t ret_val= RET_NOK;

	/* Disable ADC */
	ADC_DISABLE();

	/* Configure Voltage Ref */
	ret_val= ADC_Set_Voltage_Ref(_adc_obj->voltage_ref);

	/* Configure Result Format */
	ret_val= ADC_Set_Result_Adjustment(_adc_obj->result_format);

	/* Configure Channel */
	ret_val= ADC_Channel_Select(_adc_obj->adc_channel);

	/* Configure Prescaler */
	ret_val= ADC_Set_Prescaler(_adc_obj->prescaler);

	/* Enable ADC */
	ADC_ENABLE();

	return ret_val;
}

std_return_type_t ADC_Set_Voltage_Ref(uint8_t v_ref)
{
	switch(v_ref)
	{
		case ADC_VOLTAGE_REF_AREF:
			CLEAR_BIT(ADC_ADMUX, REFS1);
			CLEAR_BIT(ADC_ADMUX, REFS0);
		break;

		case ADC_VOLTAGE_REF_AVCC:
			CLEAR_BIT(ADC_ADMUX, REFS1);
			SET_BIT(ADC_ADMUX, REFS0);
		break;

		case ADC_VOLTAGE_REF_INTERNAL_1_1:
			SET_BIT(ADC_ADMUX, REFS1);
			SET_BIT(ADC_ADMUX, REFS0);
		break;
	}

	return RET_OK;
}

std_return_type_t ADC_Set_Result_Adjustment(uint8_t result_adjust)
{
	if(result_adjust == ADC_RESULT_RIGHT_ADJUSTMENT)
	{
		CLEAR_BIT(ADC_ADMUX, ADLAR);
	}
	else if(result_adjust == ADC_RESULT_LEFT_ADJUSTMENT)
	{
		SET_BIT(ADC_ADMUX, ADLAR);
	}

	return RET_OK;
}

std_return_type_t ADC_Channel_Select(uint8_t _channel)
{
	std_return_type_t ret_val= RET_NOK;
	ADC_ADMUX &= 0xF0;
	ADC_ADMUX |= _channel;

	switch(_channel)
	{
		case ADC_CHANNEL_ADC0: gpio_pin_set_direction(PORTC_INDEX, PIN0, INPUT); break;
		case ADC_CHANNEL_ADC1: gpio_pin_set_direction(PORTC_INDEX, PIN1, INPUT); break;
		case ADC_CHANNEL_ADC2: gpio_pin_set_direction(PORTC_INDEX, PIN2, INPUT); break;
		case ADC_CHANNEL_ADC3: gpio_pin_set_direction(PORTC_INDEX, PIN3, INPUT); break;
		case ADC_CHANNEL_ADC4: gpio_pin_set_direction(PORTC_INDEX, PIN4, INPUT); break;
		case ADC_CHANNEL_ADC5: gpio_pin_set_direction(PORTC_INDEX, PIN5, INPUT); break;
	}

	return ret_val;
}

std_return_type_t ADC_Set_Prescaler(uint8_t _prescaler)
{
	ADC_ADCSRA &= 0xF8;
	ADC_ADCSRA |= _prescaler;

	return RET_OK;
}

std_return_type_t ADC_Set_Auto_Trig_Src(uint8_t _src)
{
	ADC_ADCSRB &= 0xF8;
	ADC_ADCSRB |= _src;

	return RET_OK;
}

std_return_type_t ADC_IsConversionDone( uint8_t *conversion_status)
{
	*conversion_status= GET_BIT(ADC_ADCSRA, ADIF);		// 1 -> Conversion is done
														// 0 -> Conversion not done
	return RET_OK;
}

std_return_type_t ADC_GetConversionResult( uint16 *conversion_result, uint8_t _adjust)
{
	if(ADC_RESULT_RIGHT_ADJUSTMENT == _adjust)
	{
		*conversion_result= (uint16)(ADC_ADCL + (ADC_ADCH << 8));
	}
	else if(ADC_RESULT_LEFT_ADJUSTMENT == _adjust)
	{
		*conversion_result= (uint16)((ADC_ADCL + (ADC_ADCH << 8)) >> 6);
	}
	else
	{
		*conversion_result= (uint16)(ADC_ADCL + (ADC_ADCH << 8));
	}
	return RET_OK;
}

std_return_type_t ADC_Blocking_GetConversion(const adc_t* _adc_obj, uint16 *conversion_result)
{
	std_return_type_t ret_val= RET_NOK;
	 /* Select A/D channel */
	ADC_Channel_Select(_adc_obj->adc_channel);

	 /* Start Conversion */
	ADC_START_CONVERSION();

	 /* Check if conversion is completed */
	 while(!(GET_BIT(ADC_ADCSRA,ADIF)));

	 ret_val= ADC_GetConversionResult(conversion_result, _adc_obj->result_format);

	 return ret_val;
}

std_return_type_t ADC_Interrupt_GetConversion(const adc_t* _adc_obj, void (*ADC_InterruptCallBack) (void))
{
	std_return_type_t ret_val= RET_NOK;
	/* Configure Call Back Function */
	ret_val= ADC_Set_InterruptHandler(_adc_obj, _adc_obj->ADC_InterruptHandler);

	// Start Conversion
	ADC_START_CONVERSION();

	// Enable ADC Interrupt
	ADC_INTERRUPT_Enable();

	 return ret_val;
}

/* --------------------------- Helper Functions Definitions --------------------------- */
static std_return_type_t ADC_Set_InterruptHandler(const adc_t* _adc_obj, void (*ADC_InterruptHandler)(void))
{
	ADC_DefaultInterruptHandler= ADC_InterruptHandler;
	return RET_OK;
}

/* --------------------------- ISR --------------------------- */
void __vector_16 (void)  __attribute__((signal)) ;
void __vector_16 (void)
{
	if(ADC_DefaultInterruptHandler != NULL)
	{
		/* Clear Flag */
		ADC_INTERRUPT_FLAG_CLEAR();

		/* Call Function */
		ADC_DefaultInterruptHandler();
	}
}
