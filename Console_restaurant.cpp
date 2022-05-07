#include "Console_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

void Console_restaurant::set_menu() {
	cout << endl;
	cout << "=========================" << endl;
	cout << "식당 관리 시스템에 오신걸 환영합니다" << endl;
	cout << "1: 예약 / 2: 예약 취소 / 3: 식당 방문 / 4: 통계 / 5: 로그아웃 >>";
	cin >> menu;
}

int Console_restaurant::get_menu() {
	return menu;
}

void Console_restaurant::set_date() {
	cout << "날짜를 선택해주세요" << endl;
	cout << "*****5월****************************" << endl;
	cout << "____________________________________" << endl;
	cout << "| 일 | 월 | 화 | 수 | 목 | 금 | 토 |" << endl;
	cout << "------------------------------------" << endl;
	cout << "| 1  | 2  | 3  | 4  | 5  | 6  | 7  |" << endl;
	cout << "------------------------------------" << endl;
	cout << "5월 _일 >>";
	cin >> date;
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