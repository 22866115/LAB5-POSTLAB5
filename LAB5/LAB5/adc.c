
//rodrigolara


#include "adc.h"

void ADC_init(void) {
	ADMUX = (1 << REFS0); // AVcc con capacitor externo en AREF
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1); // Habilitar ADC, prescaler 64
}

uint16_t ADC_read(uint8_t ch) {
	ADMUX = (ADMUX & 0xF0) | (ch & 0x0F);
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));
	return ADC;
}
