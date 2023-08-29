#ifndef __STD_TYPES_H__
#define __STD_TYPES_H__

/* ------------------------------- Includes ------------------------------- */
#include <stdlib.h>

/* ------------------------------- Macros Declarations ------------------------------- */
#define RET_NOK					0
#define RET_OK					1
#define GPIO_PORT_INVALID		2
#define GPIO_PIN_INVALID		3
#define NULL_PTR				4

/* ------------------------------- data types declarations ------------------------------- */
typedef unsigned char std_return_type_t;

typedef unsigned char boolean;
typedef unsigned char uint8_t;
typedef unsigned short uint16;
typedef unsigned long uint32_t;
typedef unsigned long long uint64_t;

typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed long sint32_t;
typedef signed long long sint64_t;

typedef float float32_t;
typedef double float64_t;


#endif
