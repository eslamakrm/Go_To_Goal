#ifndef interrupt_h
#define interrupt_h

#include <avr/interrupt.h>
#include <avr/io.h>
#include "common_macros.h"
void interrupt_configuration(void);
ISR(INT0_vect);
ISR(INT1_vect);
int N_R_ticks = 0;
int N_L_ticks = 0;

#endif
