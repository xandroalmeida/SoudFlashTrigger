#ifndef DISPLAY_H_
#define DISPLAY_H_

void display_refresh(void);
void display_clear(void);
void display_init(void);

void display_print(Tuint16 n);

/*     0
 *   +---+
 *  5| 6 |1
 *   +---+
 *  4|   |2
 *   +---+ o7
 *     3
 */

#define CARACTER_0	(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5)
#define CARACTER_1	(BIT1 + BIT2)
#define CARACTER_2	(BIT0 + BIT1 + BIT3 + BIT4 + BIT6)
#define CARACTER_3	(BIT0 + BIT1 + BIT2 + BIT3 + BIT6)
#define CARACTER_4	(BIT1 + BIT2 + BIT5 + BIT6)
#define CARACTER_5	(BIT0 + BIT2 + BIT3 + BIT5 + BIT6)
#define CARACTER_6	(BIT0 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6)
#define CARACTER_7	(BIT0 + BIT1 + BIT2)
#define CARACTER_8	(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6)
#define CARACTER_9	(BIT0 + BIT1 + BIT2 + BIT3 + BIT5 + BIT6)

#define CARACTER_SPC	(0)

#define CARACTER_A	(BIT0 + BIT1 + BIT2 + BIT4 + BIT5 + BIT6)
#define CARACTER_B	(BIT2 + BIT3 + BIT4 + BIT5 + BIT6)
#define CARACTER_C	(BIT0 + BIT3 + BIT4 + BIT5)
#define CARACTER_c	(BIT3 + BIT4 + BIT6)
#define CARACTER_D	(BIT1 + BIT2 + BIT3 + BIT4 + BIT6)
#define CARACTER_E	(BIT0 + BIT3 + BIT4 + BIT5 + BIT6)
#define CARACTER_F	(BIT0 + BIT4 + BIT5 + BIT6)
#define CARACTER_G	(BIT0 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6)
#define CARACTER_H	(BIT1 + BIT2 + BIT4 + BIT5 + BIT6)
#define CARACTER_I	(BIT1 + BIT2)
#define CARACTER_J	(BIT1 + BIT2 + BIT3 + BIT4)
#define CARACTER_L	(BIT2 + BIT3 + BIT4 + BIT5)
#define CARACTER_M	(BIT0 + BIT1 + BIT2 + BIT4 + BIT5 + BIT6)
#define CARACTER_N	(BIT2 + BIT3 + BIT4 + BIT6)
#define CARACTER_O	(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5)
#define CARACTER_P	(BIT0 + BIT2 + BIT4 + BIT5 + BIT6)
#define CARACTER_Q	(BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5)
#define CARACTER_R	(BIT4 + BIT6)
#define CARACTER_S	(BIT0 + BIT2 + BIT3 + BIT5 + BIT6)
#define CARACTER_T	(BIT4 + BIT5 + BIT6)
#define CARACTER_U	(BIT1 + BIT2 + BIT3 + BIT4 + BIT5)
#define CARACTER_Z	(BIT0 + BIT1 + BIT3 + BIT4 + BIT6)

#endif
