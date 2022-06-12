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
DataBase sing_in 로직 구현중
아파트 호수 입력 로직 수현 필요
*/