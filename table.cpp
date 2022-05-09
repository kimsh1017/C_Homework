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
	cout << name << "�� ����Ǿ����ϴ�" << endl;	
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
}

