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
	void showTickets();
	void appointment(Ticket_airport*);
	void cancel(int);
	int get_mileage();
	Ticket* getTicket(int);
	int get_tickets_size();
};


#endif