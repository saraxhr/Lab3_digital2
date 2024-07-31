/*
 * ADC.h
 *
 * Created: 7/31/2024 11:02:04 AM
 *  Author: sarax
 */ 


#ifndef ADC_H
#define ADC_H

#include <avr/io.h>

void ADC_Init(void);
uint16_t ADC_Read(uint8_t channel);

#endif
