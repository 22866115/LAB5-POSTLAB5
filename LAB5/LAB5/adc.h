/*
 * adc.h
 *
 * Created: 8/04/2025 12:31:04
 *  Author: Rodrigo Lara
 */ 


#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void ADC_init(void);
uint16_t ADC_read(uint8_t ch);

#endif
