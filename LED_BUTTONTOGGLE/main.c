/*
 * LED_BUTTONTOGGLE.c
 *
 * Created: 2022-08-04 오후 4:05:57
 * Author : kccistc
 */ 

/*
=== button1 toggle 처리 ===

단, 비트연산자로 구현 한다.

1. button1을 1번 누르면 LED가 왼쪽 --> 오른쪽으로 ON

// 76543210

// 1

// 10

// 100

// 1000

// 10000

// 100000

// 10000000

2. button1을 1번 누르면 LED가 오른쪽 --> 왼쪽으로 ON

// 76543210

// 10000000

// 01000000

// 00100000

// 00010000

// 00001000

// 00000100

// 00000010

// 00000001

=== BUTTON2 처리 ===

1. button2을 1번 누르면 LED가 왼쪽 --> 오른쪽으로 ON (기존 ON시킨것 그대로 유지)

// 76543210

// 1

// 11

// 111

// 1111

// 11111

// 111111

// 1111111

// 11111111

// 00000000

2. button2을 1번 누르면 LED가 오른쪽 --> 왼쪽으로 ON (기존 ON시킨것 그대로 유지)

// 76543210

// 10000000

// 11000000

// 11100000

// 11110000

// 11111000

// 11111100

// 11111110

// 11111111

// 00000000

=== button 3 ====

1. button3을 1번 누르면 꽃이 오므라 드는 모습

// 76543210

// 10000001

// 01000010

// 00100100

// 00011000

2. button3을 1번 누르면 꽃이 피는 모습

// 00011000

// 00100100

// 01000010

// 10000001

*/

#define F_CPU 16000000UL
#include <avr/io.h>
#include "BUTTON.h"
int get_button1();
int get_button2();
extern int get_button1();  //  extern이라는 의미는 다른 파일에 있는 함수다. compile의 의미
extern int get_button2();
extern int get_button3();

int button1_state=0;  //  초기상태는 버튼을 덴 상태로 출발
int button2_state=0;
int button3_state=0;

void shift_left_led_on(void);
void shift_right_led_on(void);
void shift_stack_left_led_on(void);
void shift_stack_right_led_on(void);
void shift_flower_fallen_on(void);
void shift_flower_blooming_on(void);

void shift_left_led_on(void)
{
	for (int i = 0; i<8; i++)
	{
		PORTA = 0x01 << i;
		_delay_ms(300);
	}
}

void shift_right_led_on(void)
{
	for (int i = 0; i<8; i++)
	{
		PORTA = 0x80 >> i;
		_delay_ms(300);
	}
}

void shift_stack_left_led_on(void)
{
	PORTA = 0x00;
	for (int i = 0; i<8; i++)
	{
		PORTA |= 0x01 << i;
		_delay_ms(300);
	}
}

void shift_stack_right_led_on(void)
{
	PORTA = 0x00;
	for (int i = 0; i<8; i++)
	{
		PORTA |= 0x80 >> i;
		_delay_ms(300);
	}
}

void shift_flower_fallen_on(void)
{
	for (int i = 0; i<4; i++)
	{
		PORTA = (0x80 >> i) | (0x01 << i);
		_delay_ms(300);
	}
}

void shift_flower_blooming_on(void)
{
	for (int i = 0; i<4; i++)
	{
		PORTA = (0x10 << i) | (0x08 >> i);
		_delay_ms(300);
	}
}

int main(void)
{
    LED_DDR = 0xff;  //  DDRA = 0xff; LED출력 모드이기때문에 1로
	LED_PORT = 0x00;  // led all off
	init_button();
    
	while (1) 
    { 

		if (get_button1())
		{
			button1_state = !button1_state;
			{
				if(button1_state)
				{
					
				}
				else
				{
			        shift_right_led_on();
				}			
			}
		}
		if (get_button2())
		{
			button2_state = !button2_state;
				if(button2_state)
				{
					shift_stack_left_led_on();
				}
				else
				{
					shift_stack_right_led_on();
				}
		}
		if (get_button3())
		{
			button3_state = !button3_state;
				if(button3_state)
				{
					shift_flower_fallen_on();
				}
				else
				{
					shift_flower_blooming_on();
				}	
			
	    }
	}
}




