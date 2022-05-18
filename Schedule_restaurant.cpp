#include "Schedule_restaurant.h"

Schedule_restaurant::Schedule_restaurant() {
	date = "";
	reservation_4 = new Table[6]; // **���߿� �̸� �ٲٱ�**

	setTableSeat();
}
Schedule_restaurant::~Schedule_restaurant() {
	delete[]reservation_4;
}

void Schedule_restaurant::setDate(string date) { //���� ��¥ ���ϱ�
	this->date = date;
}

void Schedule_restaurant::setTableSeat() { // ���̺�� �¼� �� ���ϱ�
	for (int i = 0; i < 4; i++) {
		reservation_4[i].set_seat_number(4);
	}
	for (int i = 4; i < 6; i++) {
		reservation_4[i].set_seat_number(6);
	}
}



void Schedule_restaurant::appointment(UserData* User , Ticket_restaurant* appointment_data) { // ����
	int people, table;
	this->User = User;
	cout << date << endl;

	//�ο��� �Է� �ް� �¼� �����ֱ�
	people = Console_restaurant::set_people();
	show_table(people);
	
	//���� �ޱ�
	table = Console_restaurant::set_table();
	if (table != 7) {
		if (reservation_4[table - 1].get_appointed(people) == "����") {
			appointment_data->set_table_number(table);
			appointment_data->set_people(people);
			reservation_4[table - 1].appointment(User);
			User->appointment(appointment_data);
		}
		else {
			cout << "������ �Ұ����� �¼��Դϴ�" << endl;
		}
	}
	cout << endl;
}

void Schedule_restaurant::show_table(int people) {
	cout << "==============================" << endl;
	cout << "  ������������     ������������     ������������     ������������   " << endl;
	cout << " o�� 1  �� o  o�� 2  �� o  o�� 3  �� o  o�� 4  �� o " << endl;
	cout << " o��"<<reservation_4[0].get_appointed(people) << "�� o  o��" << reservation_4[1].get_appointed(people) << "�� o  o��" << reservation_4[2].get_appointed(people) << "�� o  o��" << reservation_4[3].get_appointed(people) << "�� o " << endl;
	cout << "  ������������     ������������     ������������     ������������   " << endl;
	cout << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "  ����������������   ����������������" << endl;
	cout << "  �� 5" << reservation_4[4].get_appointed(people) << "��   �� 6" << reservation_4[5].get_appointed(people) << "��          7: ���ư���" <<endl;
	cout << "  ����������������   ����������������" << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "==============================" << endl;
}

void Schedule_restaurant::cancel(int table_number) {
	reservation_4[table_number - 1].cancel();
}

bool Schedule_restaurant::checkTable(int table_number) {
	if (reservation_4[table_number - 1].get_appointed(1) == "����") {
		return false;
	}
	else {
		return true;
	}
}