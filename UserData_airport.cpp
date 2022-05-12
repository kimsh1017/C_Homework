#include "UserData.h"
#include "UserData_airport.h"

#include <iostream>
using namespace std;
#include<string>

UserData_airport::UserData_airport() {
	mileage = 0;
}

void UserData_airport::appointment(int departure , int arrival) {
	//���� Ƽ�� �����
	tickets.push_back(Ticket_airport(departure, arrival));
}

Ticket* UserData_airport::getTicket(int ticket_number) {
	return &tickets[ticket_number];
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

Ticket* UserData_airport::getTicketBack() {
	return &tickets.back();
}
