#include <iostream>
using namespace std;
#include "System.h"
#include <Windows.h>

int main() {
	system("mode con cols=130 lines=40 | title 예약 프로그램");

	System* system = new System();
	system->running();
	delete system;
}

/* 해야 할 일
* 0. 독서실 시간 중복 예외처리 - 끝
* 1. UI 수정 , 0번 누르면 돌아가기 , 헤더파일 include 수정 - 끝
* 2. 식당 walk in - 끝
* 3. console 지우기 - 끝
* 4. 로직 수정?
* 5. admin? -> 보고서에
* 6. 왕복 예약 중간에 돌아가기 -> 하나만 됨
* 7. 색깔 추가
* 8. 문자열 포맷팅?
*/

