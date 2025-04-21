#include "SERVO2.h"
#include <avr/io.h>

void SERVO2_init(void) {
    DDRD |= (1 << PD7); // OC2A
    TCCR2A = (1 << COM2A1) | (1 << WGM21) | (1 << WGM20); // Fast PWM
    TCCR2B = (1 << CS21); // Prescaler 8
    OCR2A = 75; // 1.5ms
}

void SERVO2_set(uint8_t value) {
    OCR2A = value; // 50 a 100
}