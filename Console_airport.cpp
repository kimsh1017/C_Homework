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

int Console_airport::set_departure() {
	int place = 0;
	
	while (place == 0) {
		cout << "======================" << endl;
		cout << "출발지를 선택해주세요" << endl;
		cout << "1: 1번 공항" << endl;
		cout << "2: 2번공항" << endl;
		cout << "3: 3번공항" << endl;
		cout << "4: 4번공항" << endl;
		cout << "5: 5번공항" << endl;
		cout << "출발지>>";
		cin >> place;

		if (place > 5 || place < 0) {
			cout << "잘못된 입력입니다" << endl;
			place = 0;
		}
	}
	return place;
}

int Console_airport::set_arrival() {
	int place = 0;

	while (place == 0) {
		cout << "======================" << endl;
		cout << "도착지를 선택해주세요" << endl;
		cout << "1: 1번 공항" << endl;
		cout << "2: 2번공항" << endl;
		cout << "3: 3번공항" << endl;
		cout << "4: 4번공항" << endl;
		cout << "5: 5번공항" << endl;
		cout << "도착지>>";
		cin >> place;

		if (place > 5 || place < 0) {
			cout << "잘못된 입력입니다" << endl;
			place = 0;
		}
	}
	return place;
}

int Console_airport::set_time() {
	int time = 0;
	while (time == 0) {
		cout << "시간대를 입력해주세요" << endl;
		cout << "1: 07시 / 2: 12시 / 3: 17시 >>";
		cin >> time;

		if (time > 3 || time < 0) {
			cout << "잘못된 입력입니다" << endl;
			time = 0;
		}
	}
	return time;
}

int Console_airport::set_seat_number() {
	int seat_number = 0;
	while (seat_number == 0) {
		cout << "예약을 원하는 자리를 입력해주세요 >>" << endl;
		cin >> seat_number;

		if (seat_number > 8 || seat_number < 0) {
			cout << "잘못된 입력입니다" << endl;
			seat_number = 0;
		}
	}
	return seat_number;
}

int Console_airport::set_seat_type() {
	int seat_type = 0;
	while (seat_type == 0) {
		cout << "좌석 등급을 선택해주세요 1: 이코노미 / 2: 비즈니스>>" << endl;
		cin >> seat_type;

		if (seat_type > 2 || seat_type < 0) {
			cout << "잘못된 입력입니다" << endl;
			seat_type = 0;
		}
	}
	return seat_type;
}
