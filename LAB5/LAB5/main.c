/*
 * POSTLAB5.c
 *
 * Created: 8/04/2025 12:09:07
 * Author : Rodrigo Lara
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include "adc.h"
#include "pwm.h"
#include "utils.h"
 
int main(void) {
	ADC_init();
	PWM1_init();
	PWM0_init();

	while (1) {
		uint16_t pot1 = ADC_read(0); // A0 - Servo 1
		uint16_t pot2 = ADC_read(1); // A1 - Servo 2
		uint16_t pot3 = ADC_read(2); // A2 - LED PWM

		set_PWM1A(map(pot1, 0, 1023, 1000, 4000)); // Servo 1 en D9 (OC1A)
		
		set_PWM1B(map(pot2, 0, 1023, 1000, 4000)); // Servo 2 en D10 (OC1B)
		
		set_PWM0A(map(pot3, 0, 1023, 0, 255));     // LED en D6 (OC0A)

		_delay_ms(50);
	}
}
