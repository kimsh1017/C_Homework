#ifndef USERDATA_H
#define USERDATA_H

#include <iostream>
using namespace std;
#include<string>
#include "Ticket.h"
#include "Ticket_airport.h"
#include "Ticket_restaurant.h"

class UserData {
protected:
	string name;
	string id;
	string password;

public:
	UserData();
	UserData* next;

	virtual void createUser(string);
	virtual void showData(); // 나중에는 지우자 이거

	bool checkData(string, string);
	string get_id();
	string get_name();

	virtual void cancel(int);
	virtual int get_tickets_size();

	virtual void appointment(Ticket_airport*);
	virtual void appointment(Ticket_restaurant*);

	virtual void showTickets(); //꼬인거 풀기 필요
	virtual Ticket* getTicket(int);

	virtual int get_age();
	virtual int get_mileage();
};

#endif