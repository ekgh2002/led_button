#define F_CPU 1600000000UL

#include <avr/io.h>

#include <util/delay.h>


#define LED_DDR	   DDRA // �̷��� �ϴ� ������  LED_DDR���� �ٲ��ָ� COMPILER�� �˾Ƽ� ����
#define LED_PORT   PORTA

#define BUTTON_DDR DDRD
#define BUTTON_PIN PIND // portD�� read�� �ϴ� resister , PINx�� �ϳ��� �޸� AVR���� �����ϴ� resistor, ���� 5V�� ������ 1, 0V�� ������ 0
#define BUTTON1 4 // PORTD.4
#define BUTTON2 5 // PORTD.5
#define BUTTON3 6 // PORTD.6
#define BUTTON4 7 // PORTD.7
//test//

int main(void)

{

	LED_DDR = 0xff; // DDRA = 0xff; LED��� ��� �̱� ������ 1�� ����
	BUTTON_DDR &= ~((1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3) | (1 << BUTTON4)); // input ��� : 0���� ����

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