#include "Console.h"
#include <iostream>
#include <string>
using namespace std;

string Console::id = "";
string Console::password = "";
int Console::place_menu = 0;
int Console::login_menu = 0;

void Console::set_id() {
	cout << "ID >>";
	cin >> id;
}
string Console::get_id() {
	return id;
}

void Console::set_password() {
	cout << "비밀번호 >>";
	cin >> password;
}
string Console::get_password() {
	return password;
}


void Console::set_place_menu() {
	place_menu = 0;
	while (place_menu == 0) {
		cout << "예약 프로그램을 선택하세요" << endl;
		cout << "1: 비행기 예약 / 2: 식당 예약 / 3: 독서실 예약 / 4: 종료>>";
		cin >> place_menu;

		if (place_menu > 4 || place_menu < 1) {
			cout << "잘못된 입력입니다" << endl;
			place_menu = 0;
		}
	}
}

void Console::set_login_menu() {
	login_menu = 0;
	cout << "환영합니다" << endl;
	while (login_menu == 0) {
		cout << "1: 로그인 / 2: 회원 가입>>";
		cin >> login_menu;

		if (login_menu > 2 || login_menu < 1) {
			cout << "잘못된 입력입니다" << endl;
			login_menu = 0;
		}
	}
}

int Console::get_login_menu() {
	return login_menu;
}
int Console::get_place_menu() {
	return place_menu;
}
