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
	string airport_list[5] = { "��õ","����","����","����","�뱸" };
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			airplane_list[i][j].setDeparture(airport_list[i]);
		}
	}
}

void Airport::setAirplaneArrival() {
	string airport_list[5] = { "��õ","����","����","����","�뱸" };
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
			cancel();
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
	bool round_trip = Console_airport::check_round_trip();

	departure = Console_airport::set_departure();
	arrival = Console_airport::set_arrival();

	if (departure == arrival) {
		cout << "�߸��� �Է��Դϴ�" << endl;
		cout << "������� �������� �޶���մϴ�" << endl;
	}
	else {
		if (round_trip) {
			set_route(departure, arrival);
			set_route(arrival, departure);
		}
		else {
			set_route(departure, arrival);
		}
	}
}

void Airport::set_route(int departure, int arrival) {
	string airport_list[5] = { "��õ","����","����","����","�뱸" };

	appointment_data = new Ticket_airport;
	appointment_data->set_route(departure, arrival);

	cout << endl;
	cout << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << "�� ����� " << endl;

	if (arrival > departure) {
		arrival--;
	}
	airplane_list[departure - 1][arrival - 1].appointment(User, appointment_data);
	delete appointment_data;
}

void Airport::cancel() {
	int ticket_number, departure , arrival;
	Ticket* cancel_data = NULL;

	User->showTickets();
	ticket_number = Console_airport::set_ticket_number(User->get_tickets_size());

	if (ticket_number != 0) {
		cancel_data = User->getTicket(ticket_number);
		departure = cancel_data->get_departure();
		arrival = cancel_data->get_arrival();

		if (arrival > departure) arrival--;
		airplane_list[departure-1][arrival-1].cancel(cancel_data);
		User->cancel(ticket_number);
	}
}

void Airport::showStat() {
	int menu;
	int economy = 0;
	int bussiness = 0;
	int seat_stat[8] = {0,};
	Ticket* ticket;

	menu = Console_airport::set_stat_menu();
	if (menu == 1) {
		User->showTickets();
		cout << endl;
		cout << "���ϸ��� : " << User->get_mileage() << "km" << endl;
	}
	else {
		for (int i = 0; i < User->get_tickets_size(); i++) {
			ticket = User->getTicket(i+1);
			seat_stat[ticket->get_seat_number() - 1]++;
		}
		for (int i = 0; i < 8; i++) {
			if (i < 3) bussiness += seat_stat[i];
			else economy += seat_stat[i];
		}

		cout << "============================" << endl;
		cout << "����� �¼� ��" << endl;
		for (int i = 0; i < 8; i++) {
			cout << i + 1 << "�� �¼� : " << seat_stat[i] << "ȸ" << endl;
		}
		cout << endl;
		cout << "�� ����� ���ڳ�� �¼� �� : " << economy << endl;
		cout << "�� ����� ����Ͻ� �¼� �� : " << bussiness << endl;
	}
}