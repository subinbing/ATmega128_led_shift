#define F_CPU 7372800UL

#define __DELAY_BACKWARD_COMPATIBLE__ //_delay_ms(변수) 허용 ---(원래 숫자만 들어가야함)

​

#include <avr/io.h> // I/O 레지스터 정의

#include <util/delay.h> // 시간 지연 함수용 헤더파일

​

int LED = 0x01;

unsigned char flag = 0;

​

int main(void)

{

	DDRD = 0x00; // 입력포트 설정(스위치)

	DDRA = 0xFF; // 출력포트 설정(LED)

	PORTA = 0xAA; // LED 초기상태

	​

		int time = 400;

	int LED1 = 0x01, LED2 = 0x80, LED3 = 0x01;

	​

		while (1)

		{

			//누르는 순간 LED 전체 ON (debouncing)

			if ((~PIND & 0x0F) == 0x01) //0번째 스위치를 누르면

			{

				_delay_ms(35); //채터링 방지

				PORTA = 0x00; //LED 켜짐

				while (~PIND & 0x01); //위에서부터 계속 누르고 있을때 while 값이 참이다가 스위치를 떼면 거짓이되어 다음으로 넘어감 

				_delay_ms(1000); //채터링 방지

			}

			​

				//눌렀다 뗐을 때 LED 전체 OFF (debouncing)

			else if ((~PIND & 0x0F) == 0x02) //1번째 스위치를 눌렀을때 

			{

				_delay_ms(1000); //채터링 방지

				while (~PIND & 0x02); //위에서부터 계속 누르고 있을때 while 값 참이다가 스위치를 떼면 거짓이되어 다음으로 넘어감

				PORTA = ~0x00; //LED 꺼짐,(~0x00 == 0xff)

				_delay_ms(1000); //채터링 방지

			}

			​

				//누르는 동안 LED 1개 왼쪽으로 SHIFT, 속도 증가, 일정치 도달시 초기화

			else if ((~PIND & 0x0F) == 0x04) //2번째 스위치를 눌렀을때

			{

				​

					PORTA = ~LED; //PORTA에 LED 값이 들어감

				LED = LED << 1; //LED가 한칸씩 왼쪽으로 시프트

				_delay_ms(time); //채터링 방지

				time = time - 10; //속도가 갈수록 증가하려면 10씩 딜레이 시간을 줄여주면서 점점 빠르게 함

				if (time == 20) //딜레이 시간이 20까지 줄어들면

				{

					time = 400; //다시 400으로감

				}

				if (LED > 0x80) LED = 0x01; //LED가 8번째까지 오면 LED를 다시 초기화 

			}

			​

				​

				//누르는 순간 flag 사용하여 LED 1개 

				//1번 눌렀다가 뗐을때 LED 왼쪽 shift, 2번 눌렀다가 뗐을때 LED 오른쪽 shift, 3번 눌렀다가 뗐을때 LED 정지

			else if ((~PIND & 0x0F) == 0x08) //3번째 스위치를 눌렀을때

			{

				_delay_ms(50); //채터링 방지

				flag++; // flag 증가

				//이 사이에 밑에 if, else if문이 들어오면 안되는 이유는 flag==1의 문장에서 3번째 줄까지만 실행되고 올라가서

				//또 3번째 스위치가 눌러지면 flag가 2가되어 flag==2 문장에서 3번째 줄까지 실행되다 보면 

				//LED가 0번째와 7번째 불만 서로 바꿔가면서 깜빡이게됨

				while (~PIND & 0x08); //위에서부터 계속 누를때 while 값이 참이다가 스위치를 떼면 while 값이 거짓이 되면서 다음 문장이 실행됨

			}

			if (flag == 1) //flag가 1이되면

			{

				_delay_ms(50); //채터링 방지

				PORTA = ~LED1; //PORTA에 LED1 출력

				LED1 = LED1 << 1; //왼쪽으로 시프트

				if (LED1 > 0x80) LED1 = 0x01; //LED가 8번째까지 오면 LED를 다시 초기화 

			}

			else if (flag == 2) //flag가 2가되면 

			{

				_delay_ms(50); //채터링 방지

				PORTA = ~LED2; //PORTA에 LED2 출력

				LED2 = LED2 >> 1; //오른쪽으로 시프트

				if (LED2 < 0x01) LED2 = 0x80; //LED가 1번째까지 오면 LED를 다시 초기화 

			}

			else if (flag == 3) //flag가 3이되면

			{

				_delay_ms(50); //채터링 방지

				PORTA = ~LED3; //PORTA에 LED3 출력(여기서 LED3의 값은 위에서 초기화 해준 값인 0x01이 됨

			}

			else if (flag > 3) //flag가 3이상이 되면

			{

				flag = 1; //flag가 다시 1부터 시작함

			}

		}

	​

}