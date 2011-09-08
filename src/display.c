/*
 * display.c
 *
 *  Created on: Sep 4, 2011
 *      Author: Alexandro D. Almeida
 */

#include "femtoos_code.h"
#include "avr/pgmspace.h"
#include "display.h"
#include "common.h"

#define DISPLAY_NUM_DIGITS	4

PROGMEM static Tuint08 numtbl[127] = {
		CARACTER_0,
		CARACTER_1,
		CARACTER_2,
		CARACTER_3,
		CARACTER_4,
		CARACTER_5,
		CARACTER_6,
		CARACTER_7,
		CARACTER_8,
		CARACTER_9,
		CARACTER_A,
		CARACTER_B,
		CARACTER_C,
		CARACTER_D,
		CARACTER_E,
		CARACTER_F
};

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

void display_print(Tuint16 n)
{
	display_buffer[0] = pgm_read_byte_near(numtbl + (n >> 12));
	display_buffer[1] = pgm_read_byte_near(numtbl + (n >> 8));
	display_buffer[2] = pgm_read_byte_near(numtbl + (n >> 4));
	display_buffer[3] = pgm_read_byte_near(numtbl + (n & 0x0f));
}

void appLoop_DisplayTask(void) {
	Tuint16 n = 0;

	while (true) {
		display_print(OSCCAL);
		taskDelayFromNow(20);

	}
}
