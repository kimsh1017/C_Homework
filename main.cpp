#include <iostream>
using namespace std;
#include "System.h"

int main() {
	System* system = new System();
	system->running();
	delete system;
}

/* 해야 할 일
* 1. 비행기 좌석별 가격 만들기, 좌석 8개로 바꾸기 - 완료
* 1-1 0번 누르면 돌아가기 구현
* 2. 식당 walk-in 테이블 만들기
* 3. 독서실 만들기
* 
* (4) 비행기 왕복 예약시 하나 취소하면 나머지도 취소?
* (5) 비행기 왕복 예약시 출발 도착 시간 설정 예외처리
* 
* 4. console 지우기? include "windows.h" system("cls") -> system 객체 변경
*/
