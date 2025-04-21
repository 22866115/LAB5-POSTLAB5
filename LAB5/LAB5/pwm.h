/*
 * pwm.h
 *
 * Created: 8/04/2025 12:29:26
 *  Author: Rodrigo Lara
 */ 


#ifndef PWM_H
#define PWM_H

#include <avr/io.h>

void PWM1_init(void);
void set_PWM1A(uint16_t value);
void set_PWM1B(uint16_t value);

void PWM0_init(void);
void set_PWM0A(uint8_t value);

#endif
