/*
 * display.c
 *
 *  Created on: Sep 4, 2011
 *      Author: Alexandro D. Almeida
 */

#include "femtoos_code.h"
#include "display.h"
#include "common.h"

#define DISPLAY_NUM_DIGITS	4

static Tuint08 display_buffer[4];
static Tuint08 current_digit;

#define select_digit(digit)\
	PORTC |= BIT1+BIT2+BIT3+BIT4;\
	PORTC &= 0xff ^(1 << (digit+PB1));


#define write_display_segments(segments)\
	PORTB = ~((Tuint08)segments);

void display_refresh(void)
{
	select_digit(current_digit);
	write_display_segments(display_buffer[current_digit]);
	if (++current_digit > DISPLAY_NUM_DIGITS)
		current_digit = 0;
}

inline void display_clear(void)
{
	Tuint08 i;
	for (i = 0; i < DISPLAY_NUM_DIGITS; i++) display_buffer[i] = 0xff;
}

void display_init(void)
{
	display_clear();
}


void appLoop_DisplayTask(void) {
	while (true) {
		display_buffer[0] = CARACTER_0;
		display_buffer[1] = CARACTER_1;
		display_buffer[2] = CARACTER_2;
		display_buffer[3] = CARACTER_3;
		taskDelayFromNow(20);
		display_buffer[0] = CARACTER_4;
		display_buffer[1] = CARACTER_5;
		display_buffer[2] = CARACTER_6;
		display_buffer[3] = CARACTER_7;
		taskDelayFromNow(20);

	}
}
