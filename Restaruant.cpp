#include "Restaurant.h"
#include "Console_restaurant.h"
#include "UserData_restaurant.h"

#include <iostream>
#include <string>
#include "Ticket_restaurant.h"
using namespace std;

Restaurant::Restaurant() {
	this->User = NULL;
	schedules = new Schedule_restaurant[7];
	walk_in_table = "";

	set_date(); // 스케줄에 요일 날짜 설정
}
Restaurant::~Restaurant() {
	delete[]schedules;
}

void Restaurant::set_date() { // 요일 날짜 설정
	schedules[0].setDate("5월 1일 일요일");
	schedules[1].setDate("5월 2일 월요일");
	schedules[2].setDate("5월 3일 화요일");
	schedules[3].setDate("5월 4일 수요일");
	schedules[4].setDate("5월 5일 목요일");
	schedules[5].setDate("5월 6일 금요일");
	schedules[6].setDate("5월 7일 토요일");
}


void Restaurant::sign_in(UserData* User) { //로그인된 유저 정보 받아오기
	this->User = User;
}

void Restaurant::appointment() {
	int date = Console_restaurant::set_date();

	appointment_data = new Ticket_restaurant;
	appointment_data->set_date(date);
	schedules[date - 1].appointment(User,appointment_data);
}

void Restaurant::walk_in() { // walk-in 구현 
	int walk_in_menu = 0;

	if (User->get_id() == walk_in_table) { // 테이블 구현이 맞을까? or walk_in 객체 구현?
		cout << "현재 식사중입니다" << endl;
		cout << "식사를 종료하시겠습니까?" << endl;
		cout << "예 : 1 / 아니오 : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			walk_in_table = "";
		}
	}
	else {
		if (walk_in_queue.empty()) {
			if (walk_in_table == "") {
				cout << "테이블이 남아있습니다. 바로 식사하시겠습니까?" << endl;
				cout << "예 : 1 / 아니오 : 2" << endl;
				cin >> walk_in_menu;
				if (walk_in_menu == 1) {
					walk_in_table = User->get_id();
				}
			}
			else {
				cout << "모든 테이블이 식사 중입니다" << endl;
				cout << "대기하시겠습니까?" << endl;
				cout << "예 : 1 / 아니오 : 2" << endl;
				cin >> walk_in_menu;
				if (walk_in_menu == 1) {
					add_queue();
				}
			}
		}

		else if (User->get_id() == walk_in_queue.front()) {
			// 앞 식사 종료되서 식사 시작 가능할 때?
			if (walk_in_table == "") {
				cout << "테이블에 자리가 생겼습니다. 바로 식사하시겠습니까?" << endl;
				cout << "예 : 1 / 아니오 : 2" << endl;
				cin >> walk_in_menu;
				if (walk_in_menu == 1) {
					walk_in_table = walk_in_queue.front();
					walk_in_queue.pop_front();
				}
			}
			else {
				cout << "현재 대기순번은 1번 입니다" << endl;
			}
		}
		else {
			for (int i = 1; i < walk_in_queue.size(); i++) {
				if (User->get_id() == walk_in_queue[i]) {
					cout << "현재 대기 번호는" << i+1 << "번 입니다" << endl;
					walk_in_menu = 1;
				}
			}
			if (walk_in_menu == 0) {
				cout << "현재" << walk_in_queue.size() << "명이 대기중입니다" << endl;
				cout << "대기하시겠습니까?" << endl;
				cout << "예 : 1 / 아니오 : 2 >>" << endl;
				cin >> walk_in_menu;

				if (walk_in_menu == 1) {
					add_queue();
				}
			}
		}
	}
}

void Restaurant::runServer(UserData* User) {
	int menu;
	this->User = User;

	menu = Console_restaurant::set_menu();
	while (menu!= 5) {  //menu 5 = 로그아웃
		switch (menu) {
		case 1:
			if (User->get_age() <= 7) {
				cout << "7세 이하 미취학 아동은 예약이 불가능합니다." << endl;
			}
			else {
				appointment();
			}
			break;
		case 2:
			cancel();
			break;
		case 3: 
			walk_in();
			break;
		case 4:
			showStat();
			break;
		}
		menu = Console_restaurant::set_menu();
	}
}

void Restaurant::cancel() {
	Ticket* ticket = NULL;
	int ticket_number;

	// User 에서 테이블 정보 받아오기
	User->showTickets();
	ticket_number = Console_restaurant::set_ticket_number(User->get_tickets_size());
	ticket = User->getTicket(ticket_number);

	// 받은 정보로 테이블 객체 접근해 취소하기
	if (ticket != NULL) {
		schedules[ticket->get_date() - 1].cancel(ticket->get_table_number());
		User->cancel(ticket_number);
	}
}

void Restaurant::add_queue() {
	walk_in_queue.push_back(User->get_id());
}

void Restaurant::showStat() {
	// 대충 통계 보여주는 함수

	int stat_menu = 0;
	int table_stat[6] = { 0, };
	while (stat_menu == 0) {
		cout << "1 : 내 예약 현황 보기 / 2 : 테이블별 예약 횟수 보기 >>";
		cin >> stat_menu;

		if (stat_menu > 2 || stat_menu < 1) {
			stat_menu = 0;
			cout << "잘못된 입력입니다" << endl;
		}
	}

	if (stat_menu == 1) { // 고객의 지금까지의 예약 횟수 보여주기
		User->showTickets();
	}
	else { // 테이블별 예약된 횟수 보여주기
		for (int i = 0; i < 6; i++) {
			table_stat[i] = 0;
		}


		for (int i = 0; i < 7; i++) {
			for (int j = 0; j < 6; j++) {
				if (schedules[i].checkTable(j+1)) {
					table_stat[j]++;
				}
			}
		}

		for (int i = 0; i < 6; i++) {
			cout << i+1 << "번 테이블 예약 횟수 : " << table_stat[i] << endl;
		}
	}
}
