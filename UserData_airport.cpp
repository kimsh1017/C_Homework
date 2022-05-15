#include "UserData.h"
#include "UserData_airport.h"

#include <iostream>
using namespace std;
#include<string>

UserData_airport::UserData_airport() {
	mileage = 0;
}

void UserData_airport::showTickets() {
	cout << "============================" << endl;
	cout << "���� �������� Ƽ��" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < tickets.size(); i++) {
		cout << i + 1 << "�� Ƽ��" << endl;
		tickets[i].showTicket();
		cout << "------------------------------" << endl;
	}
}

void UserData_airport::appointment(Ticket_airport* appointment_data) {
	tickets.push_back(Ticket_airport(*appointment_data));
	mileage += 100;
}
void UserData_airport::cancel(int ticket_number) {
	tickets.erase(tickets.begin() + ticket_number - 1);
	mileage -= 100;
}

int UserData_airport::get_mileage() {
	return mileage;
}

Ticket* UserData_airport::getTicket(int ticket_number) {
	// 0�϶� ����ó�� & �ݺ�?
	if (ticket_number == 0) {
		return NULL;
	}
	else {
		return &tickets[ticket_number - 1];
	}
}
int UserData_airport::get_tickets_size() {
	int temp = tickets.size();
	return temp;
}