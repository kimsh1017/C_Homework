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
	this->name = User->get_name();
	cout << name << "님 예약되었습니다" << endl;	
}

string Table::get_appointed(int people) {
	if (this->name == "---" && people <= this->seat_number) {
		return "가능";
	}
	else {
		return "불가";
	}
}

void Table::cancel() {
	name = "---";
}

