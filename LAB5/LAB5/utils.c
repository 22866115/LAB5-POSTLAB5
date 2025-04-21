/*
 * utils.c
 *
 * Created: 8/04/2025 13:03:28
 *  Author: Rodrigo Lara
 */ 
#include "utils.h"

long map(long x, long in_min, long in_max, long out_min, long out_max) {
	return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
