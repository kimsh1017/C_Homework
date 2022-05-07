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
		cout << "�̹� ����� �¼��Դϴ�" << endl;
	}
	else {
		this->name = User->get_name();
		cout << name << "�� ����Ǿ����ϴ�" << endl;
	}
}

string Table::get_appointed() {
	if (this->name == "---") {
		return "����";
	}
	else {
		return "�Ұ�";
	}
}


