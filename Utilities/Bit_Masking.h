/*
 * Bit_Masking.h
 *
 * Created: 2/12/2023 1:26:06 PM
 *  Author: LAP TECH
 */ 


#ifndef BIT_MASKING_H_
#define BIT_MASKING_H_

#define SET_BIT(PORT_NUM,PIN_NUM)			PORT_NUM |= (1 << PIN_NUM)
#define CLEAR_BIT(PORT_NUM,PIN_NUM)			PORT_NUM &= ~(1 << PIN_NUM)
#define TOGGLE_BIT(PORT_NUM,PIN_NUM)		PORT_NUM ^= (1 << PIN_NUM)
#define READ_BIT(PORT_NUM,PIN_NUM)			((PORT_NUM >> PIN_NUM) & 0x01)

#endif /* BIT_MASKING_H_ */