#include "Console.h"

void moveCursor(int x, int y) { // 커서 움직이는 전역함수
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

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

	clean(0);
	cout << endl;

	while (place_menu == 0) {
		cout << "예약 프로그램을 선택하세요" << endl;
		cout << "1: 비행기 예약 / 2: 식당 예약 / 3: 독서실 예약 / 4: 종료>>";
		cin >> place_menu;

		if (place_menu > 4 || place_menu < 1) {
			cout << "잘못된 입력입니다" << endl;
			place_menu = 0;
			clean(500);
			cout << endl;
		}
	}
	return place_menu;
}

int Console::set_login_menu() {
	int login_menu = -1;
	while (login_menu == -1) {
		cout << "1: 로그인 / 2: 회원 가입 / 0: 돌아가기>>";
		cin >> login_menu;

		if (login_menu > 2 || login_menu < 0) {
			cout << "잘못된 입력입니다" << endl;
			login_menu = -1;
		}
	}
	return login_menu;
}

string Console::set_apartment_number() {
	string apartment_number = "";
	
	cout << "세대를 입력해주세요 : 101동 ___호 >>";
	cout << "(101~999사이의 숫자로 입력해주세요)" << endl;
	moveCursor(28, 4);
	cin >> apartment_number;

	return apartment_number;
}

void Console::clean(int delay) {
	Sleep(delay);
	system("cls");
}

int Console::set_age() {
	int age;
	cout << "나이 >>";
	cin >> age;
	return age;
}


