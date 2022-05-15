#include "Schedule_airplane.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Schedule_airplane::Schedule_airplane() {
	time = "";

	seats = new Seat[8]; // 3�� ����Ͻ� 5�� ���ڳ��
	set_seat_cost();
}
Schedule_airplane::~Schedule_airplane() {

	delete[]seats;
}
void Schedule_airplane::set_seat_cost() { //�̰� �� ��ĥ��
	for (int i = 0; i < 8; i++) {
		i < 3 ? seats[i].set_cost_bussiness() : seats[i].set_cost_economy();
	}
}

void Schedule_airplane::setTime(string time) {
	this->time = time;
}

void Schedule_airplane::appointment(UserData* User,Ticket_airport* appointment_data) {
	int seat_number;
	float cost;

	cost = Console_airport::set_cost();

	showSeats(cost);
	seat_number = Console_airport::set_seat_number();

	if (seats[seat_number - 1].get_cost() <= cost) {
		if (seats[seat_number - 1].get_name() != "---") {
			cout << "�̹� ����� �¼��Դϴ�" << endl;
		}
		else {
			appointment_data->set_seat_number(seat_number);
			seats[seat_number - 1].appointment(User);
			User->appointment(appointment_data);
		}
	}
	else {
		cout << "�Է��� ������ �ʰ��ϴ� �¼��Դϴ�" << endl;
	}
}

void Schedule_airplane::showSeats(float cost) {

	cout << "===========================" << endl;
	
	for (int i = 0; i < 8; i++) {
		cout << " "<< i + 1 << "�� �¼� " << "|";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		if (i<3) cout <<" ����Ͻ� " << "|";
		else cout << " ���ڳ�� " << "|";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		if(i<3)cout << "  "<< seats[i].get_cost() << "����  |";
		else cout << "  " << seats[i].get_cost() << " ����  |";
	}
	cout << endl;

	for (int i = 0; i < 8; i++) {
		if (seats[i].get_name() == "---" && seats[i].get_cost() <= cost) {
			cout << "   ����   |";
		}
		else {
			cout << "   �Ұ�   |";
		}
	}
	cout << endl;
}

void Schedule_airplane::cancel(Ticket* cancel_data) {
	int seat_number;
	seat_number = cancel_data->get_seat_number();

	seats[seat_number - 1].cancel();
}
