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
		string airport_list[5] = { "인천","김포","제주","김해","대구" };
		cout << "======================" << endl;
		cout << "출발지를 선택해주세요" << endl;
		for (int i = 0; i < 5; i++) {
			cout << i + 1 << " : " << airport_list[i] << "공항" << endl;
		}
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
		cout << "도착지를 선택해주세요" << endl;
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
		cout << "예약을 원하는 자리를 입력해주세요 >>";
		cin >> seat_number;

		if (seat_number > 8 || seat_number < 0) {
			cout << "잘못된 입력입니다" << endl;
			seat_number = 0;
		}
	}
	return seat_number;
}

bool Console_airport::check_round_trip() {
	int temp = 0;
	cout << endl;

	while (temp == 0) {
		cout << "1: 왕복 / 2: 편도 >>";
		cin >> temp;

		if (temp > 2 || temp < 0) {
			temp = 0;
		}
	}
	return temp==1 ? true : false;
}

int Console_airport::set_ticket_number(int max) {
	int ticket_number = -1;
	while (ticket_number == -1) {
		cout << "취소하고 싶은 예약 번호를 입력하세요 (돌아가기 : 0 )>>";
		cin >> ticket_number;

		if (ticket_number < 0 || ticket_number > max) {
			cout << "잘못된 입력입니다" << endl;
			ticket_number = -1;
		}
	}
	return ticket_number;
}

float Console_airport::set_cost() {
	int menu = 0;
	float cost = 0;
	while (menu == 0) {
		cout << "1. 가격 상한선 설정하기 / 2. 모든 좌석 보기 >>";
		cin >> menu;
		if (menu > 2 || menu < 0) {
			menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}
	
	if (menu == 2) {
		cost = 11;
	}
	while (cost == 0) {
		cout << " 가격 : __만 원 이하 >>";
		cin >> cost;

		if (cost < 0) {
			cout << "잘못된 입력입니다" << endl;
		}
	}
	return cost;
}