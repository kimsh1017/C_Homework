#include <iostream>
using namespace std;
#include "System.h"
#include <Windows.h>

int main() {
	//콘솔 화면 크기 전환
	system("mode con cols=130 lines=40 | title 예약 프로그램");

	System* system = new System();
	system->running();
	delete system;
}


/*
airport 구현 성공
식당 구현성공

식당 ui 고치기 (컴파일 시간 줄이기 / walk-in ui 개선)
독서실 구현 필요
나이 예약 제한

예외처리 구현
코드 깔끔하게?
*/