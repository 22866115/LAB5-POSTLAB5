#include "LEDAR.h"
#include <avr/io.h>

void LEDAR_init(void) {
    DDRD |= (1 << PD6); // OC0A
    TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00);
    TCCR0B = (1 << CS01); // Prescaler 8
}

void LEDAR_set(uint8_t value) {
    OCR0A = value;
}