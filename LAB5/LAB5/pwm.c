/*
 * pwm.c
 *
 * Created: 8/04/2025 12:30:15
 *  Author: Rodrigo Lara
 */ 



#include "pwm.h"

void PWM1_init(void) {
	DDRB |= (1 << PB1) | (1 << PB2); // OC1A (D9), OC1B (D10)
	TCCR1A = (1 << COM1A1) | (1 << COM1B1) | (1 << WGM11);
	TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Modo 14 (Fast PWM), prescaler 8
	ICR1 = 40000; // TOP = 20 ms (50Hz)
}

void set_PWM1A(uint16_t value) {
	OCR1A = value;
}

void set_PWM1B(uint16_t value) {
	OCR1B = value;
}

void PWM0_init(void) {
	DDRD |= (1 << PD6); // OC0A (D6)
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // Fast PWM, OC0A habilitado
	TCCR0B = (1 << CS01); // Prescaler 8
}

void set_PWM0A(uint8_t value) {
	OCR0A = value;
}
