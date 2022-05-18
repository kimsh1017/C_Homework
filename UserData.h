#ifndef USERDATA_H
#define USERDATA_H

#include <iostream>
using namespace std;
#include<string>

#include "Ticket.h"
#include "Ticket_airport.h"
#include "Ticket_restaurant.h"
#include "Ticket_apart.h"

class UserData {
protected:
	string name;
	string id;
	string password;

public:
	UserData();
	UserData* next;

	virtual void createUser(string);

	bool checkData(string, string);
	virtual string get_id();
	string get_name();

	virtual void cancel(int);
	virtual int get_tickets_size();

	virtual void appointment(Ticket_airport*);
	virtual void appointment(Ticket_restaurant*);
	virtual void appointment(Ticket_apart*);

	virtual void showTickets(); //꼬인거 풀기 필요
	virtual Ticket* getTicket(int);

	virtual int get_age();
	virtual int get_mileage();

	//apart
	virtual int getTotalTime(int) { return 0; }
};

#endif