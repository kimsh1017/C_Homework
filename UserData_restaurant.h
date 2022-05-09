#ifndef USERDATA_RESTAURANT_H
#define USERDATA_RESTAURANT_H
#include <iostream>
using namespace std;
#include<string>

#include "UserData.h"
#include "Ticket_restaurant.h"
#include "Table.h"
#include <vector>

class UserData_restaurant : public UserData {
	int age;
	vector <Ticket_restaurant> tickets;
public:
	UserData_restaurant();
	void createUser(string);
	void cancel(int);
	void appointment(int,int, int);
	void showData();


	int get_age();
	void showTickets();
	Ticket* getTicket(int);
};

#endif