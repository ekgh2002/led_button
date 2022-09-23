/*
 * BUTTON.c
 *
 * Created: 2022-08-04 오후 4:12:16
 *  Author: kccistc
 */ 
 #include "BUTTON.h"
 void init_button()
 {
	 BUTTON_DDR &= ~((1 << BUTTON1) | (1 << BUTTON2) | (1 << BUTTON3) | (1 << BUTTON4));  //  input : 0으로 설정
 }
 
 
 int get_button1()
 {
	 static uint8_t prev_state=0;  //  button의 상태 0 : off 1 : on
	 uint8_t current_state;  //  unsigned char = current state
	 
	 current_state = BUTTON_PIN & (1 << BUTTON1);  //  button1 값을 읽는다. 0x10
	 if(prev_state == 0 && current_state !=0)  //  button이 처음 눌려진 상태
	 {
		 _delay_ms(60);  //  noise가 지나가기를 기다리는 상태
		 prev_state=1;  //  처음 눌려진 상태가 아니다.
		 return 0;      //  아직도 진짜로 눌러진 상태가 아니다.
	 }
	 else if (prev_state == 1 && current_state == 0)  //  button이 눌렸다(prev_state == 1) 떼어진 상태 (current_state == 0)
	 {
		 prev_state=0;
		  _delay_ms(30);
		 return 1;  //  완전히 눌렸다 떼어진 상태로 인정
	 }
	 return 0;  //  아직 완전히 s/w를 눌렀다 떼지 않은 상태
 }
 int get_button2()    // port4 (button1)에 연결된 것을 읽어들이는 함수
{
	 static uint8_t prev_state=0;   // 버튼의 상태 0: off, 1: on
	 uint8_t current_state;    // uint8_t : open source type -> unsigned char = uint8_t
	 
	 current_state = BUTTON_PIN & (1 << BUTTON2);      // button1 값을 읽는다  0x10
	 if (prev_state == 0 && current_state !=0)         // 버튼이 처음 눌려진 상태
	 {
		 _delay_ms(60);          // Noise가 지나가기를 기다리는 시간
		 prev_state=1;           // 처음 눌려진 상태가 아니다
		 return 0;              // 진짜로 눌려진 상태가 아니다
	 }
	 else if (prev_state == 1 && current_state ==0) // 버튼이 눌렸다가(prev==1) 떼어진 상태(current==0) -> high (5V)에서 low (0V)로 떨어지는 상태
	 {
		 prev_state=0;
		 _delay_ms(30);
		 return 1;             // 완전히 눌렀다 떼어진 상태로 인정
	 }
	 return 0;   // 아직 완전히 S/W를 눌렀다 뗴지 않은 상태
 }
  int get_button3()    // port4 (button1)에 연결된 것을 읽어들이는 함수
  {
	  static uint8_t prev_state=0;   // 버튼의 상태 0: off, 1: on
	  uint8_t current_state;    // uint8_t : open source type -> unsigned char = uint8_t
	  
	  current_state = BUTTON_PIN & (1 << BUTTON3);      // button1 값을 읽는다  0x10
	  if (prev_state == 0 && current_state !=0)         // 버튼이 처음 눌려진 상태
	  {
		  _delay_ms(60);          // Noise가 지나가기를 기다리는 시간
		  prev_state=1;           // 처음 눌려진 상태가 아니다
		  return 0;              // 진짜로 눌려진 상태가 아니다
	  }
	  else if (prev_state == 1 && current_state ==0) // 버튼이 눌렸다가(prev==1) 떼어진 상태(current==0) -> high (5V)에서 low (0V)로 떨어지는 상태
	  {
		  prev_state=0;
		  _delay_ms(30);
		  return 1;             // 완전히 눌렀다 떼어진 상태로 인정
	  }
	  return 0;   // 아직 완전히 S/W를 눌렀다 뗴지 않은 상태
  }
 
