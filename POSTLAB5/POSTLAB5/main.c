//Universidad del valle de Guatemala
//Rodrigo Javier Lara Lopez
//22866
//Postlab#5


#include <avr/io.h>
#include <util/delay.h>
#include "ADC.h"
#include "SERVO1.h"
#include "SERVO2.h"
#include "LEDAR.h"

int map(int x, int in_min, int in_max, int out_min, int out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main(void) {
    ADC_init();
    SERVO1_init();
    SERVO2_init();
    LEDAR_init();

    while (1) {
        uint16_t pot1 = ADC_read(0);  // lectura de valor de potenciometro en A0
        uint16_t pot2 = ADC_read(1);  // lectura de potencioemtro en A1
        uint16_t pot3 = ADC_read(2);  // Variable de almacenar el valor del potenciometro en A2

        SERVO1_set(map(pot1, 0, 1023, 2000, 4000));
        SERVO2_set(map(pot2, 0, 1023, 50, 100)); // Timer2 escala
        LEDAR_set(map(pot3, 0, 1023, 0, 255));

        _delay_ms(20); // Delay para no saturar los servos
    }

    return 0;
}