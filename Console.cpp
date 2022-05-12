#include "Console.h"

string Console::set_id() {
	string id;
	cout << "ID >>";
	cin >> id;
	return id;
}

string Console::set_password() {
	string password;

	cout << "비밀번호 >>";
	cin >> password;
	return password;
}


int Console::set_place_menu() {
	int place_menu = 0;
	while (place_menu == 0) {
		cout << "예약 프로그램을 선택하세요" << endl;
		cout << "1: 비행기 예약 / 2: 식당 예약 / 3: 독서실 예약 / 4: 종료>>";
		cin >> place_menu;

		if (place_menu > 4 || place_menu < 1) {
			cout << "잘못된 입력입니다" << endl;
			place_menu = 0;
		}
	}
	return place_menu;
}

int Console::set_login_menu() {
	int login_menu = 0;
	cout << "환영합니다" << endl;
	while (login_menu == 0) {
		cout << "1: 로그인 / 2: 회원 가입>>";
		cin >> login_menu;

		if (login_menu > 2 || login_menu < 1) {
			cout << "잘못된 입력입니다" << endl;
			login_menu = 0;
		}
	}
	return login_menu;
}

