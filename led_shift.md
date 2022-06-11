01. I/O 포트 레지스터 (비트 속성, DDRx, PORTx, PINx)

< 레지스터의 비트 속성 >
- 읽기 / 쓰기 (R/W)
R/W : 읽기/쓰기가 가능한 비트
R : 읽기만 가능한 비트
W : 쓰기만 가능한 비트

- 초기값 : 전원이 공급된 직후 또는 리셋 직후 각 레지스터가 갖는 값, N/A(Not Available)로 표시된 것은 정의 되지 않는 경우로 어떤 값을 가지는지 모름

- 데이터 방향 레지스터 : DDRx
1. 입출력 방향 결정
2. 값이 1이면 출력 설정 (PORTx)
3. 값이 0이면 입력 설정 (PINx)
![image](https://user-images.githubusercontent.com/87634136/173195710-2f8b58ea-894a-485a-9156-6bd9fa8fa07c.png)

- 포트 데이터 레지스터 : PORTx
1. 값이 1이면 HIGH를 출력
2. 값이 0이면 LOW를 출력 
![image](https://user-images.githubusercontent.com/87634136/173195741-81c1f801-5508-4c0b-b662-703dbf4a21ff.png)

- 포트 입력 핀 레지스터 : PINx
어느 비트에서 입력 받을지 정하는 레지스터
![image](https://user-images.githubusercontent.com/87634136/173195773-b7ca5393-2701-4eb5-9c40-7f47a267b60d.png)


02. LED 
- LED(Light Emitting Diode - 발광다이오드)
![image](https://user-images.githubusercontent.com/87634136/173195780-efbc9e5f-a3ad-4fd9-8bc5-a9305b32c880.png)

- 회색으로 된 2줄이 부품외 다리
- LED의 극성 알아보는 방법
   -> 다리의 길이 (긴쪽 +, 짧은쪽 -)
   -> LED의 내부 (' ㄱ ' 모양은 ' - ',  ' l ' 모양은 ' + ')
  ![image](https://user-images.githubusercontent.com/87634136/173195794-88e473d4-fabc-4da9-bafa-76c5b4b30a5b.png)
- 다이오드란 전류를 한 방향으로만 (+에서 -로) 흐르게 하고, 반대 방향으로 흐르지 못하게 하는 반도체 소자

--->LED 데이터 시트
![image](https://user-images.githubusercontent.com/87634136/173195835-328b2493-c0a0-450c-8a49-f5e682640267.png)

- LED PULL-UP / PULL-DOWN

< LED PULL- UP >
![image](https://user-images.githubusercontent.com/87634136/173195849-6cd7b2b5-2948-477a-bf67-9181227a9342.png)

< LED PULL - DOWN >
![image](https://user-images.githubusercontent.com/87634136/173195862-8a81b6e7-57fc-49b3-9b50-c9ed3ef9cb4f.png)


03. SWITCH
- 스위치 내부 구조
![image](https://user-images.githubusercontent.com/87634136/173195883-12e8d850-eecc-41fe-b95b-a329892f59dc.png)

- 스위치 연결 방법
![image](https://user-images.githubusercontent.com/87634136/173195897-89a0d96b-12e2-459d-84c5-24c5264d5d69.png)


< 플로팅 (floating) >
![image](https://user-images.githubusercontent.com/87634136/173195903-9b583e22-9d8b-4e1a-8839-180f68708e43.png)

플로팅 상태
- 스위치를 누르면 전류가 흐르고, 스위치를 떼면 전류가 흐르지 않아야 하는데 '플로팅' 상태가 되면 스위치가 정상 작동하지 않게 됨
- 즉, 스위치가 눌려지지 않은 상태인데도 전류가 흐르게 되는 문제가 발생하고 그 반대 현상도 발생하게 됨


< SW PULL_UP >
- 스위치 OFF (스위치가 열려 있을 때)
: 5V에서 입출력 핀으로 전류 흐름 -> 1이 입력
![image](https://user-images.githubusercontent.com/87634136/173195934-35d59073-3614-4e68-bcad-b03f1fe63921.png)

- 스위치 ON (스위치가 닫혀 있을 때)
: 가장 낮은 쪽인 GND쪽으로 전류 흐름 -> 0이 입력
![image](https://user-images.githubusercontent.com/87634136/173195943-bbea5b2c-6900-4a91-9811-d366201f05a9.png)


< SW PULL_DOWN >
- 스위치 OFF (스위치가 열려 있을 때)
: 입출력 핀에서 GND로 전류 흐름 -> 0이 입력 
![image](https://user-images.githubusercontent.com/87634136/173195960-c6173e8b-8db1-4a50-9b64-8917678391cd.png)

- 스위치 ON (스위치가 닫혀 있을 때)
: 5V에서 입출력 핀으로 전류 흐름 -> 1이 입력
![image](https://user-images.githubusercontent.com/87634136/173195972-ca50e6c2-c94e-48ec-acd7-0a8463f36ebb.png)

- 채터링 & 디바운싱
채터링 : 스위치가 닫히고 열리는 순간에 기계적인 진동에 의해 매우 짧은 시간 안에 스위치가 붙었다가 떨어지는 것을 반복하는 현상 ---> 방지 ---> 디바운스 : 짧은 시간에 여러번 스위치의 상태를 확인하는 방법
![image](https://user-images.githubusercontent.com/87634136/173195978-2e092f1d-ede2-4da1-8701-94715f9e190c.png)

- 스위칭 디바운싱 구조
![image](https://user-images.githubusercontent.com/87634136/173195983-a4208243-c887-4425-9a71-4c740593410e.png)

- Blocking 방식 & Nonblocking 방식 
![image](https://user-images.githubusercontent.com/87634136/173195995-12b95f27-3c25-4dee-a743-bbd2a073813d.png)

04. GPIO
- GPIO 입력, 출력 순서
GPIO ( General Purpose Input / Output ) : 기본적인 입출력, 마이크로 컨트롤러의 핀을 입력 또는 출력 용도로 사용할 수 있게 하는 기능
![image](https://user-images.githubusercontent.com/87634136/173196003-f7f09bc8-22b2-45d9-a57e-779f6069cfd0.png)
