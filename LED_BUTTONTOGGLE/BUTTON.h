/*
 * BUTTON.h
 *
 * Created: 2022-08-04 오후 4:08:52
 *  Author: kccistc
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

#define LED_DDR		DDRA  //  이렇게 하는 이유는 LED_DDR에서 바꾸기 위해 컴파일러만 바꿔주면 됨
#define LED_PORT	PORTA
#define BUTTON_DDR	DDRD
#define BUTTON_PIN  PIND  //  PORTD를 read 하는 resister
						  //  PINx는 하나의 메모리 AVR에서 제공하는 register
						  //  전압 5V를 읽으면 1, 0V를 읽으면 0
#define BUTTON1     4	  //  PORTD.4
#define BUTTON2     5	  //  PORTD.5
#define BUTTON3     6	  //  PORTD.6
#define BUTTON4     7	  //  PORTD.7





#endif /* BUTTON_H_ */