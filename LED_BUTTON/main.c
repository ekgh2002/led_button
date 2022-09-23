#define F_CPU 1600000000UL

#include <avr/io.h>

#include <util/delay.h>


#define LED_DDR	   DDRA // 이렇게 하는 이유는  LED_DDR에서 바꿔주면 COMPILER가 알아서 변경
#define LED_PORT   PORTA

#define BUTTON_DDR DDRD
#define BUTTON_PIN PIND // portD를 read를 하는 resister , PINx는 하나의 메모리 AVR에서 제공하는 resistor, 전압 5V를 읽으면 1, 0V를 읽으면 0
#define BUTTON1 4 // PORTD.4
#define BUTTON2 5 // PORTD.5
#define BUTTON3 6 // PORTD.6
#define BUTTON4 7 // PORTD.7


int main(void)

{

	LED_DDR = 0xff; // DDRA = 0xff; LED출력 모드 이기 때문에 1로 설정
	BUTTON_DDR &= ~((1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3) | (1 << BUTTON4)); // input 모드 : 0으로 설정

	while (1)

	{
		if(BUTTON_PIN & (1 << BUTTON1)) // =if(BUTTON_PIN & (1 << BUTTON1) == 1)
		{
			LED_PORT = 0xff;
		}
		if(BUTTON_PIN & (1 << BUTTON2)) // =if(BUTTON_PIN & (1 << BUTTON1) == 1)
		{
			LED_PORT = 0x00;
		}
		if(BUTTON_PIN & (1 << BUTTON3)) // =if(BUTTON_PIN & (1 << BUTTON1) == 1)
		{
			LED_PORT = 0b10101010;
		}
		if(BUTTON_PIN & (1 << BUTTON4)) // =if(BUTTON_PIN & (1 << BUTTON1) == 1)
		{
			LED_PORT = 0b01010101;
		}
	}
}