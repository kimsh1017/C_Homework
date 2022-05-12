#include "Console_airport.h"
#include <iostream>
#include <string>
using namespace std;

int Console_airport::set_menu() {
	int menu = 0;

	while (menu == 0) {
		cout << endl;
		cout << "=========================" << endl;
		cout << "비행기 예약 시스템에 오신걸 환영합니다" << endl;
		cout << "1: 예약 / 2: 예약 취소 / 3: 통계 / 4: 로그아웃 >>";
		cin >> menu;

		if (menu > 4 || menu < 1) { //예외처리
			menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return menu;
}

int  Console_airport::set_date() {
	int date = 0;

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
	return date;
}