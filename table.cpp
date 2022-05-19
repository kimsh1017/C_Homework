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
	cout << name << "�� ����Ǿ����ϴ�" << endl;
	Console_restaurant::clean(1000);
}

string Table::get_appointed(int people) {
	if (this->name == "---" && people <= this->seat_number) {
		return "����";
	}
	else {
		return "�Ұ�";
	}
}

void Table::cancel() {
	name = "---";
	id = "";
	cout << "��ҵǾ����ϴ�" << endl;
	Sleep(1000);
}
string Table::get_name() {
	return name;
}
string Table::get_id() {
	return id;
}

