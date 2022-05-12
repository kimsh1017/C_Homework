#include "Schedule_airplane.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Schedule_airplane::Schedule_airplane() {
	time = "";
	economy = new Seat[8];
	bussiness = new Seat[8];
}
Schedule_airplane::~Schedule_airplane() {
	delete[]economy;
	delete[]bussiness;
}
void Schedule_airplane::setTime(string time) {
	this->time = time;
}

void Schedule_airplane::appointment(UserData* User) {
	int seat_number, seat_type;
	Ticket* ticket;
	ticket = User->getTicketBack();

	showSeats();
	seat_type = Console_airport::set_seat_type();
	seat_number = Console_airport::set_seat_number();

	if (seat_type == 1) {
		if (economy[seat_number].get_name() == "---") {
			ticket->set_seat(seat_type, seat_number);
			economy[seat_number - 1].appointment(User);
		}
		else {
			cout << "�̹� ����� �¼��Դϴ�" << endl;
			// ���� Ticket ����ó���� ?
		}
	}
	else {
		if (bussiness[seat_number].get_name() == "---") {
			ticket->set_seat(seat_type, seat_number);
			bussiness[seat_number - 1].appointment(User);
		}
		else {
			cout << "�̹� ����� �¼��Դϴ�" << endl;
		}
	}
}

void Schedule_airplane::showSeats() {
	cout << "���ڳ�̼�" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i+1 << ":" << economy[i].get_name() << " ";
	}
	cout << endl;
	cout << "����Ͻ���" << endl;
	for (int i = 0; i < 8; i++) {
		cout << i+1 << ":" << bussiness[i].get_name() << " ";
	}
	cout << endl;
}