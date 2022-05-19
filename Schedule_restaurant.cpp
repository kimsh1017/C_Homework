#include "Schedule_restaurant.h"

Schedule_restaurant::Schedule_restaurant() {
	date = "";
	reservation_4 = new Table[6]; // **나중에 이름 바꾸기**

	setTableSeat();
}
Schedule_restaurant::~Schedule_restaurant() {
	delete[]reservation_4;
}

void Schedule_restaurant::setDate(string date) { //요일 날짜 정하기
	this->date = date;
}

void Schedule_restaurant::setTableSeat() { // 테이블당 좌석 수 정하기
	for (int i = 0; i < 4; i++) {
		reservation_4[i].set_seat_number(4);
	}
	for (int i = 4; i < 6; i++) {
		reservation_4[i].set_seat_number(6);
	}
}



void Schedule_restaurant::appointment(UserData* User , Ticket_restaurant* appointment_data) { // 예약
	int people, table;
	this->User = User;
	cout << date << endl;

	//인원수 입력 받고 좌석 보여주기
	people = Console_restaurant::set_people(appointment_data);
	appointment_data->set_people(people);

	if (people != 0) {
		//테이블 예약 받기
		show_table(appointment_data);
		table = Console_restaurant::set_table();
		if (table != 0) {
			if (reservation_4[table - 1].get_appointed(people) == "가능") {
				appointment_data->set_table_number(table);

				reservation_4[table - 1].appointment(User);
				User->appointment(appointment_data);
			}
			else {
				cout << "예약이 불가능한 좌석입니다" << endl;
				Sleep(1000);
			}
		}
	}
	cout << endl;
}

void Schedule_restaurant::show_table(Ticket_restaurant* appointment_data) {
	int people = appointment_data->get_people();
	int date = appointment_data->get_date();

	Console_restaurant::clean(0);
	cout << endl;
	cout << "[5월 " << date << "일] 방문인원 : " << people << "명" << endl;
	cout << endl;
	cout << "======================================================" << endl;
	cout << "  ┌────┐     ┌────┐     ┌────┐     ┌────┐   " << endl;
	cout << " o│ 1  │ o  o│ 2  │ o  o│ 3  │ o  o│ 4  │ o " << endl;
	cout << " o│"<<reservation_4[0].get_appointed(people) << "│ o  o│" << reservation_4[1].get_appointed(people) << "│ o  o│" << reservation_4[2].get_appointed(people) << "│ o  o│" << reservation_4[3].get_appointed(people) << "│ o " << endl;
	cout << "  └────┘     └────┘     └────┘     └────┘   " << endl;
	cout << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "  ┌──────┐   ┌──────┐" << endl;
	cout << "  │ 5" << reservation_4[4].get_appointed(people) << "│   │ 6" << reservation_4[5].get_appointed(people) << "│          (0 : 돌아가기)" <<endl;
	cout << "  └──────┘   └──────┘" << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "======================================================" << endl;
}

void Schedule_restaurant::cancel(int table_number) {
	reservation_4[table_number - 1].cancel();
}

bool Schedule_restaurant::checkTable(int table_number) {
	if (reservation_4[table_number - 1].get_appointed(1) == "가능") {
		return false;
	}
	else {
		return true;
	}
}