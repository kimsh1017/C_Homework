#include "Table.h"
#include "UserData.h"

Table::Table() {
	name = "---";
	seat_number = 0;
}

void Table::set_seat_number(int number) {
	this->seat_number = number;
}

void Table::appointment(UserData* User) {
	if (this->name != "---") {
		cout << "이미 예약된 좌석입니다" << endl;
	}
	else {
		this->name = User->get_name();
		cout << name << "님 예약되었습니다" << endl;
	}
}

string Table::get_appointed() {
	if (this->name == "---") {
		return "가능";
	}
	else {
		return "불가";
	}
}


