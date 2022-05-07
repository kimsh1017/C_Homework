#include "Schedule_restaurant.h"
#include "Table.h"
#include "Console_restaurant.h"

#include <iostream>
#include <string>
using namespace std;

void Schedule_restaurant::setTableSeat() {
	for (int i = 0; i < 4; i++) {
		reservation_4[i].set_seat_number(4);
	}
	for (int i = 0; i < 2; i++) {
		reservation_4[i].set_seat_number(6);
	}
}

Schedule_restaurant::Schedule_restaurant() {
	date = "";
	reservation_4 = new Table[4]; // �̰� ��ü�� �и��ϱ�?
	reservation_6 = new Table[2];

	setTableSeat();
}
void Schedule_restaurant::setDate(string date) {
	this->date = date;
}

void Schedule_restaurant::appointment(UserData* User) {
	int n;
	this->User = User;
	cout << date << endl;
	Console_restaurant::set_people();
	show_table(Console_restaurant::get_people());
	
	cout << "�����Ͻðڽ��ϱ�? (��:1 /�ƴϿ�:0)>>";
	cin >> n;
	if (n == 1) {
		reservation_4[0].appointment(User);
	}
}

void Schedule_restaurant::show_table(int people) {
	User->showData();
	cout << "========================" << endl;
	cout << "  ������������  " << endl;
	cout << "o �� 1  �� o" << endl;
	cout << "o ��"<<reservation_4[0].get_appointed() << "�� o" << endl;
	cout << "  ������������  " << endl;
}