#ifndef USERDATA_AIRPORT_H
#define USERDATA_AIRPORT_H
#include <iostream>
using namespace std;
#include<string>

#include "UserData.h"
#include <vector>
#include "Ticket_airport.h"

class UserData_airport : public UserData {
	int mileage;
	vector <Ticket_airport> tickets;
public:
	UserData_airport();
	void appointment(int, int);
	Ticket* getTicket(int);
	Ticket* getTicketBack();
	void showTickets();
};


#endif