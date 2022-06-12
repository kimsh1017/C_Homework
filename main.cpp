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
로그인 구현 성공
user 데이터 가공해서 예약 시작

예외처리 구현
코드 깔끔하게?
*/