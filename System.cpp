#include "System.h"
#include "UserData.h"
#include "Login.h"
#include <iostream>
using namespace std;
#include<string>

System::System() {
	place_menu = -1;
	sign_menu = -1;
	login = new Login;
}

void System::get_place() {
	cout << "프로그램 선택" << endl;
	cout << "1: 비행기 예약 / 2: 식당 예약 / 3: 독서실 예약 / 4: 종료>>";
	cin >> place_menu;
}
void System::get_sign() {
	cout << "환영합니다" << endl;
	cout << "1: 로그인 / 2: 회원 가입>>";
	cin >> sign_menu;
}

void System::running() {
	get_place();
	while (place_menu != 4) {
		get_sign();
		if (sign_menu == 1) {
			if (login->sign_in(place_menu)) {
				UserNow = login->getUser();
				cout << "환영합니다" << endl;
				UserNow->showData();
			}
			else {
				cout << "정보가 올바르지 않습니다" << endl;
			}
		}
		else {
			login->sign_up(place_menu);
		}
		get_place();
	}
}