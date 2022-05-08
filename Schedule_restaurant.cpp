#include "Schedule_restaurant.h"
#include "Table.h"
#include "Console_restaurant.h"

#include <iostream>
#include <string>
using namespace std;

void Schedule_restaurant::setTableSeat() {
	for (int i = 0; i < 4; i++) {
		reservation_4[i].set_seat_number(4);
	}
	for (int i = 0; i < 2; i++) {
		reservation_6[i].set_seat_number(6);
	}
}

Schedule_restaurant::Schedule_restaurant() {
	date = "";
	reservation_4 = new Table[4]; // 이거 객체로 분리하기?
	reservation_6 = new Table[2];

	setTableSeat();
}
void Schedule_restaurant::setDate(string date) {
	this->date = date;
}

void Schedule_restaurant::appointment(UserData* User) {
	this->User = User;
	cout << date << endl;

	//인원수 입력 받고 좌석 보여주기
	Console_restaurant::set_people();
	show_table(Console_restaurant::get_people());
	
	//예약 받기
	Console_restaurant::set_table();
	if (Console_restaurant::get_table() / 5 == 0) {
		if (reservation_4[Console_restaurant::get_table() - 1].get_appointed(Console_restaurant::get_people()) == "가능") {
			reservation_4[Console_restaurant::get_table() - 1].appointment(User);
			User->appointment(Console_restaurant::get_date(), Console_restaurant::get_table() , Console_restaurant::get_people(),&reservation_4[Console_restaurant::get_table() - 1]);
		}
		else {
			cout << "예약이 불가능한 좌석입니다" << endl;
		}
	}
	else if(Console_restaurant::get_table() != 7) {
		if (reservation_6[Console_restaurant::get_table() - 5].get_appointed(Console_restaurant::get_people()) == "가능") {
			reservation_6[Console_restaurant::get_table() - 5].appointment(User);
			User->appointment(Console_restaurant::get_date(), Console_restaurant::get_table(), Console_restaurant::get_people(), &reservation_4[Console_restaurant::get_table() - 1]);
		}
		else {
			cout << "예약이 불가능한 좌석입니다" << endl;
		}
	}
	cout << endl;
}

void Schedule_restaurant::show_table(int people) {
	cout << "==============================" << endl;
	cout << "  ┌────┐     ┌────┐     ┌────┐     ┌────┐   " << endl;
	cout << " o│ 1  │ o  o│ 2  │ o  o│ 3  │ o  o│ 4  │ o " << endl;
	cout << " o│"<<reservation_4[0].get_appointed(people) << "│ o  o│" << reservation_4[1].get_appointed(people) << "│ o  o│" << reservation_4[2].get_appointed(people) << "│ o  o│" << reservation_4[3].get_appointed(people) << "│ o " << endl;
	cout << "  └────┘     └────┘     └────┘     └────┘   " << endl;
	cout << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "  ┌──────┐   ┌──────┐" << endl;
	cout << "  │ 5" << reservation_6[0].get_appointed(people) << "│   │ 6" << reservation_6[1].get_appointed(people) << "│          7: 돌아가기" <<endl;
	cout << "  └──────┘   └──────┘" << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "==============================" << endl;
}