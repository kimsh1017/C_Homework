#include "Table.h"

Table::Table() {
	name = "---";
	id = "";
	seat_number = 0;
}

void Table::set_seat_number(int number) {
	this->seat_number = number;
}

void Table::appointment(UserData* User) {
	this->name = User->get_name();
	this->id = User->get_id();
	cout << endl;
	cout << name << "님 예약되었습니다" << endl;
	Console_restaurant::clean(500);
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
	id = "";
}
string Table::get_name() {
	return name;
}
string Table::get_id() {
	return id;
}

