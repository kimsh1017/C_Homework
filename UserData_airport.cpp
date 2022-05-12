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
	cout << "현재 보유중인 티켓" << endl;
	for (int i = 0; i < tickets.size(); i++) {
		cout << i + 1 << "번 티켓" << endl;
		tickets[i].showTicket();
		cout << "------------------------------" << endl;
	}
}

void UserData_airport::appointment(Ticket_airport* appointment_data) {
	tickets.push_back(Ticket_airport(*appointment_data));
}
