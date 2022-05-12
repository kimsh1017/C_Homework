#include "Airport.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Airport::Airport() {
	User = NULL;
	airplane_list = new Airplane * [5];
	appointment_data = NULL;
	
	for (int i = 0; i < 5; i++) { // ����� ��� �����
		airplane_list[i] = new Airplane[4];
	}
	setAirplaneDeparture(); //����� ����
	setAirplaneArrival(); // ������ ����
}
Airport::~Airport() {
	for (int i = 0; i < 5; i++) {
		delete []airplane_list[i];
	}
	delete []airplane_list;
}

void Airport::sign_in(UserData* User) {
	this->User = User;
}

void Airport::setAirplaneDeparture() {
	string airport_list[5] = { "1������","2������","3������","4������","5������" };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			airplane_list[i][j].setDeparture(airport_list[i]);
		}
	}
}

void Airport::setAirplaneArrival() {
	string airport_list[5] = { "1������","2������","3������","4������","5������" };
	int temp;
	for (int i = 0; i < 5; i++) {
		temp = 0;
		for (int j = 0; j < 4; j++) {
			if (temp == i) { temp++; }
			airplane_list[i][j].setArrival(airport_list[temp]);
			temp++;
		}
	}
}

void Airport::show_airplane_list() { // ������ ��� ���� ���
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			cout << airplane_list[i][j].getDeparture() << "->" << airplane_list[i][j].getArrival() << endl;
		}
		cout << "======================" << endl;
	}
}

void Airport::runServer() {
	int menu = 0;
	menu = Console_airport::set_menu();
	while (menu != 4) {
		switch (menu) {
		case 1:
			appointment();
			break;
		case 2:
			cout << "���� ���" << endl;
			break;
		case 3:
			showStat();
			break;
		}
		menu = Console_airport::set_menu();
	}
	cout << "����� ���� �ý����� �����մϴ�" << endl;
}

void Airport::appointment() {
	int departure, arrival;
	departure = Console_airport::set_departure();
	arrival = Console_airport::set_arrival();

	if (departure == arrival) {
		cout << "�߸��� �Է��Դϴ�" << endl;
		cout << "������� �������� �޶���մϴ�" << endl;
	}
	else {
		if (arrival > departure) {
			arrival--;
		}
		appointment_data = new Ticket_airport();
		appointment_data->set_route(departure, arrival);
		airplane_list[departure - 1][arrival - 1].appointment(User, appointment_data);
	}
}

void Airport::showStat() {
	User->showTickets();
}