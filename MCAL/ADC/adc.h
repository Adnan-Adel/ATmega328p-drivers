/*
 * adc.h
 *
 * Created: 7/10/2023 9:22:29 PM
 *  Author: Adnan
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "../DIO/dio.h"

/* -------------------------------------- Macro Declarations -------------------------------------- */

// ADMUX Pins
#define MUX0  0
#define MUX1  1
#define MUX2  2
#define MUX3  3
#define ADLAR 5
#define REFS0 6
#define REFS1 7

// ADCSRA Pins
#define ADPS0  0
#define ADPS1  1
#define ADPS2  2
#define ADIE   3
#define ADIF   4
#define ADATE  5
#define ADSC   6
#define ADEN   7

/* -------------------------------------- Data Type Declarations -------------------------------------- */

typedef enum
{
	ADC_VOLTAGE_REF_AREF= 0,		// AREF, Internal Vref turned off
	ADC_VOLTAGE_REF_AVCC,			// AVCC with external capacitor at AREF pin
	ADC_VOLTAGE_REF_INTERNAL_11,	// Internal 1.1V Voltage Reference with external capacitor at AREF pin
}adc_voltage_ref_t;

typedef enum
{
	ADC_RESULT_RIGHT_ADJUSTMENT= 0,
	ADC_RESULT_LEFT_ADJUSTMENT
}adc_result_adjustment_t;

typedef enum
{
    ADC_CHANNEL_AN0= 0,
    ADC_CHANNEL_AN1,
    ADC_CHANNEL_AN2,        
    ADC_CHANNEL_AN3,
    ADC_CHANNEL_AN4,         
    ADC_CHANNEL_AN5              
}adc_channel_select_t;


typedef enum{
    ADC_CONVERSION_CLOCK_FOSC_DIV_2 = 1,
    ADC_CONVERSION_CLOCK_FOSC_DIV_4,
    ADC_CONVERSION_CLOCK_FOSC_DIV_8,
    ADC_CONVERSION_CLOCK_FOSC_DIV_16,
    ADC_CONVERSION_CLOCK_FOSC_DIV_32,
    ADC_CONVERSION_CLOCK_FOSC_DIV_64,
    ADC_CONVERSION_CLOCK_FOSC_DIV_128
}adc_Prescaler_t;

/* -------------------------------------- Functions Declarations -------------------------------------- */

void ADC_Init(adc_Prescaler_t _prescaler, adc_voltage_ref_t _vref, adc_result_adjustment_t _adjust);
void ADC_SelectChannel(adc_channel_select_t _channel);
void ADC_StartConversion();
void ADC_IsConversionDone( uint8_t *conversion_status);
void ADC_GetConversionResult( uint16 *conversion_result, adc_result_adjustment_t _adjust);
void ADC_Blocking_GetConversion(adc_channel_select_t _channel, uint16 *conversion_result, adc_result_adjustment_t _adjust);


#endif /* ADC_H_ */