#include "Restaurant.h"
#include "Console_restaurant.h"
#include "UserData_restaurant.h"

#include <iostream>
#include <string>
using namespace std;

int Console_restaurant::menu = 0;
int Console_restaurant::date = 0;
int Console_restaurant::people = 0;
int Console_restaurant::table = 0;

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
	Console_restaurant::set_date();
	schedules[Console_restaurant::get_date() - 1].appointment(User);
}

void Restaurant::walk_in() {
	cout << "대충 walk-in" << endl;
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
		case 3:
		case 4:
		case 5:
			cout << "로그아웃 합니다" << endl;
			break;
		}
		Console_restaurant::set_menu();
	}
}

void Restaurant::cancel() {
	Console_restaurant::set_date();
	schedules[Console_restaurant::get_date() - 1].cancel(User);
}

