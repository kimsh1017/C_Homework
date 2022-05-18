#ifndef USERDATA_RESTAURANT_H
#define USERDATA_RESTAURANT_H
#include <iostream>
using namespace std;
#include<string>

#include "UserData.h"
#include "Ticket.h"
#include "Ticket_restaurant.h"
#include <vector>

class UserData_restaurant : public UserData {
	int age;
	vector <Ticket_restaurant> tickets;
public:
	UserData_restaurant();
	void createUser(string);
	void cancel(int);
	void appointment(Ticket_restaurant*);
	void showData();


	int get_age();
	void showTickets();
	Ticket* getTicket(int);
	int get_tickets_size();
};

#endif