#include "Schedule_restaurant.h"

Schedule_restaurant::Schedule_restaurant() {
	date = "";
	tables = new Table[6]; // **���߿� �̸� �ٲٱ�**

	setTableSeat();
}
Schedule_restaurant::~Schedule_restaurant() {
	delete[]tables;
}

void Schedule_restaurant::setDate(string date) { //���� ��¥ ���ϱ�
	this->date = date;
}

void Schedule_restaurant::setTableSeat() { // ���̺�� �¼� �� ���ϱ�
	for (int i = 0; i < 4; i++) {
		tables[i].set_seat_number(4);
	}
	for (int i = 4; i < 6; i++) {
		tables[i].set_seat_number(6);
	}
}



void Schedule_restaurant::appointment(Ticket_restaurant* reservation) { // ����
	int people, table_number;
	cout << date << endl;

	if (reservation->get_table_number() != 0) {
		table_number = reservation->get_table_number();
		tables[table_number - 1].appointment(reservation->get_id());
	}
	else {
		//�ο��� �Է� �ް� �¼� �����ֱ�
		people = Console_restaurant::set_people(reservation);
		reservation->set_people(people);

		if (people != 0) {
			//���̺� ���� �ޱ�
			show_table(reservation);
			table_number = Console_restaurant::set_table();
			if (table_number != 0) {
				if (tables[table_number - 1].get_appointed(people) == "����") {
					reservation->set_table_number(table_number);
					tables[table_number - 1].appointment(reservation->get_id());
				}
				else {
					cout << "������ �Ұ����� �¼��Դϴ�" << endl;
					Sleep(1000);
				}
			}
		}
		cout << endl;
	}
}

void Schedule_restaurant::show_table(Ticket_restaurant* appointment_data) {
	int people = appointment_data->get_people();
	int date = appointment_data->get_date();

	Console_restaurant::clean(0);
	cout << endl;
	cout << "[5�� " << date << "��] �湮�ο� : " << people << "��" << endl;
	cout << endl;
	cout << "======================================================" << endl;
	cout << "  ������������     ������������     ������������     ������������   " << endl;
	cout << " o�� 1  �� o  o�� 2  �� o  o�� 3  �� o  o�� 4  �� o " << endl;
	cout << " o��"<<tables[0].get_appointed(people) << "�� o  o��" << tables[1].get_appointed(people) << "�� o  o��" << tables[2].get_appointed(people) << "�� o  o��" << tables[3].get_appointed(people) << "�� o " << endl;
	cout << "  ������������     ������������     ������������     ������������   " << endl;
	cout << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "  ����������������   ����������������" << endl;
	cout << "  �� 5" << tables[4].get_appointed(people) << "��   �� 6" << tables[5].get_appointed(people) << "��          (0 : ���ư���)" <<endl;
	cout << "  ����������������   ����������������" << endl;
	cout << "    o o o      o o o  " << endl;
	cout << "======================================================" << endl;
}

void Schedule_restaurant::cancel(Ticket_restaurant* cancel_data) {
	int table_number = cancel_data->get_table_number();
	tables[table_number - 1].cancel();
}

bool Schedule_restaurant::checkTable(int table_number) {
	if (tables[table_number - 1].get_appointed(1) == "����") {
		return false;
	}
	else {
		return true;
	}
}