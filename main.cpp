#include <iostream>
using namespace std;
#include "System.h"

int main() {
	System* system = new System();
	system->running();
	delete system;
}

/* 해야 할 일
* 0. 독서실 시간 중복 예외처리 - 끝
* 1. UI 수정 , 0번 누르면 돌아가기 , 헤더파일 include 수정 - ㄱㄱ
* 2. 식당 walk in - 끝
* 3. console 지우기 - ㄱㄱ
* 4. 로직 수정?
* 5. admin?
*/
