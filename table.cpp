#include "Table.h"

Table::Table() {
	id = "---";
	seat_number = 0;
}

void Table::set_seat_number(int number) {
	this->seat_number = number;
}

void Table::appointment(string id) {
	this->id = id;
}

string Table::get_appointed(int people) {
	if (this->id == "---" && people <= this->seat_number) {
		return "가능";
	}
	else {
		return "불가";
	}
}

void Table::cancel() {
	id = "---";
	cout << "취소되었습니다" << endl;
	Sleep(1000);
}
string Table::get_id() {
	return id;
}

