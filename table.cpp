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
		return "����";
	}
	else {
		return "�Ұ�";
	}
}

void Table::cancel() {
	id = "---";
	cout << "��ҵǾ����ϴ�" << endl;
	Sleep(1000);
}
string Table::get_id() {
	return id;
}

