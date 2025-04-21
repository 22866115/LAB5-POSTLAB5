#include "SERVO1.h"
#include <avr/io.h>

void SERVO1_init(void) {
    DDRB |= (1 << PB1); // OC1A
    TCCR1A = (1 << COM1A1) | (1 << WGM11);
    TCCR1B = (1 << WGM13) | (1 << WGM12) | (1 << CS11); // Prescaler 8
    ICR1 = 39999; // 20 ms periodo
}

void SERVO1_set(uint16_t ticks) {
    OCR1A = ticks;
}