#include "Restaurant.h"
#include "Console_restaurant.h"
#include "UserData_restaurant.h"

#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

int Console_restaurant::menu = 0;
int Console_restaurant::date = 0;
int Console_restaurant::people = 0;
int Console_restaurant::table = 0;
int Console_restaurant::ticket_number = 0;

void Restaurant::set_date() {
	schedules[0].setDate("5월 1일 일요일");
	schedules[1].setDate("5월 2일 월요일");
	schedules[2].setDate("5월 3일 화요일");
	schedules[3].setDate("5월 4일 수요일");
	schedules[4].setDate("5월 5일 목요일");
	schedules[5].setDate("5월 6일 금요일");
	schedules[6].setDate("5월 7일 토요일");
}

Restaurant::Restaurant() {
	this->User = NULL;
	schedules = new Schedule_restaurant[7];
	set_date();
}
void Restaurant::sign_in(UserData* User) {
	this->User = User;
}

void Restaurant::appointment() {
	Console_restaurant::set_date(); // 예외처리
	schedules[Console_restaurant::get_date() - 1].appointment(User);
}

void Restaurant::walk_in() {
	int walk_in_menu = 0;
	if (walk_in_queue.empty()) {
		cout << "테이블이 남아있습니다. 바로 식사하시겠습니까?" << endl;
		cout << "예 : 1 / 아니오 : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			add_queue();
		}
	}
	else if (User->get_id() == walk_in_queue.front()) {
		// 앞 식사 종료되서 식사 시작 가능할 때?
		int walk_in_menu = 0;
		cout << "식사를 종료하시겠습니까?" << endl;
		cout << "예 : 1 / 아니오 : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			walk_in_queue.pop();
		}
	}
	else {
		int walk_in_menu = 0;
		cout << "현재" << walk_in_queue.size() << "명이 대기중입니다" << endl;
		cout << "대기하시겠습니까?" << endl;
		cout << "예 : 1 / 아니오 : 2" << endl;
		cin >> walk_in_menu;
		if (walk_in_menu == 1) {
			add_queue();
		}
	}
}

void Restaurant::open() {
	Console_restaurant::set_menu();
	while (Console_restaurant::get_menu() != 5) {
		switch (Console_restaurant::get_menu()) {
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
			break;
		case 5:
			cout << "로그아웃 합니다" << endl;
			break;
		}
		Console_restaurant::set_menu();
	}
}

void Restaurant::cancel() {
	// User 에서 테이블 정보 받아오기
	// 받은 정보로 테이블 객체 접근해 취소하기
	Ticket* ticket = NULL;

	User->showTickets();
	Console_restaurant::set_ticket_number();

	ticket = User->getTicket(Console_restaurant::get_ticket_number());
	if (ticket != NULL) {
		schedules[ticket->get_date() - 1].cancel(ticket->get_table_number());
	}
	User->cancel(Console_restaurant::get_ticket_number());
}

void Restaurant::add_queue() {
	walk_in_queue.push(User->get_id());
}
