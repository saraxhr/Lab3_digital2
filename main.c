/*
 * esclavo_entregable.c
 *
 * Created: 7/31/2024 11:01:32 AM
 * Author : sarax
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "spi.h"
#include "adc.h"

int main(void) {
	SPI_SlaveInit();
	ADC_Init();
	
	while (1) {
		uint16_t pot1 = ADC_Read(4); // Read from ADC channel 4 (A4)
		uint16_t pot2 = ADC_Read(5); // Read from ADC channel 5 (A5)

		SPI_SlaveReceive(); // Wait for master to initiate communication
		SPI_SlaveTransmit(pot1 >> 2); // Transmit 8-bit value (higher 8 bits of 10-bit ADC value)
		_delay_ms(10);
		SPI_SlaveReceive(); // Wait for master to initiate communication
		SPI_SlaveTransmit(pot2 >> 2); // Transmit 8-bit value (higher 8 bits of 10-bit ADC value)
	}
}
