/*
 * SoundFlashTrigger - Copyright (C) 2011 Alexandr Dias de Almeida
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Please note that, due to the GPLv3 license, for application of this
 * work and/or combined work in embedded systems special obligations apply.
 * If these are not to you liking, please know the Femto OS is dual
 * licensed. A commercial license and support are available.
 * See http://www.femtoos.org/ for details.
 */

/* This this the only include needed in your code .*/
#include "femtoos_code.h"
#include "common.h"


/* Different delays for the blinkers. */
#define delay03  2229U
#define delay02  1218U
#define delay01   666U
#define delay00   364U

/* This is called once at system boot, and before the creating of any of
 * the tasks. Use it to initialize the hardware. */
void appBoot(void) {

	DDRB = BIT7 + BIT6 + BIT5 + BIT4 + BIT3 + BIT2 + BIT1 + BIT0;
	DDRC = BIT5 + BIT4 + BIT3 + BIT2 + BIT1;

	display_init();
}

void appTick00(void) {
	display_refresh();
}

void appTick08(void) {

}

void HandleAdc(void) __attribute__ ( ( signal ) );
void HandleAdc(void) {
	devLedPORT = ~(~devLedPORT + 0x10);
}

void SIG_ADC(void) __attribute__ ( ( signal, naked, used, externally_visible ) );
void SIG_ADC(void) {
	isrBegin();
	HandleAdc();
	taskDisableGlobalInterrupts();
	isrEndReturn();
}

