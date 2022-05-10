#include "Console_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

void Console_restaurant::set_menu() {
	menu = 0;

	while (menu == 0) {
		cout << endl;
		cout << "=========================" << endl;
		cout << "식당 관리 시스템에 오신걸 환영합니다" << endl;
		cout << "1: 예약 / 2: 예약 취소 / 3: 식당 방문 / 4: 통계 / 5: 로그아웃 >>";
		cin >> menu;

		if (menu > 5 || menu < 1) { //예외처리
			menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
}

int Console_restaurant::get_menu() {
	return menu;
}

void Console_restaurant::set_date() {
	date = 0;

	while (date == 0) {
		cout << "날짜를 선택해주세요" << endl;
		cout << "*****5월****************************" << endl;
		cout << "____________________________________" << endl;
		cout << "| 일 | 월 | 화 | 수 | 목 | 금 | 토 |" << endl;
		cout << "------------------------------------" << endl;
		cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
		cout << "------------------------------------" << endl;
		cout << "5월 _일 >>";
		cin >> date;

		if (date > 7 || date < 1) { //예외처리
			date = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
}

int Console_restaurant::get_date() {
	return date;
}


void Console_restaurant::set_people() {
	cout << "방문 인원 >>";
	cin >> people;
}

int Console_restaurant::get_people() {
	return people;
}

void Console_restaurant::set_table() {
	table = 0;

	while (table == 0) {
		cout << "\'불가\'라고 쓰인 좌석은 예약할 수 없습니다" << endl;
		cout << "예약하실 좌석의 번호를 입력해주세요 >>";
		cin >> table;

		if (table > 7 || table < 1) {
			table = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
}

int Console_restaurant::get_table() {
	return table;
}

void Console_restaurant::set_ticket_number() {
	cout << "취소하고 싶은 예약 번호를 입력하세요 (돌아가기 : 0 )>>";
	cin >> ticket_number;
}
int Console_restaurant::get_ticket_number() {
	return ticket_number;
}
