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
	for (int i = 0; i < tickets.size(); i++) {
		cout << i + 1 << "�� Ƽ��" << endl;
		tickets[i].showTicket();
		cout << "------------------------------" << endl;
	}
}

void UserData_airport::appointment(Ticket_airport* appointment_data) {
	tickets.push_back(Ticket_airport(*appointment_data));
}
