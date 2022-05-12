#ifndef USERDATA_H
#define USERDATA_H

#include <iostream>
using namespace std;
#include<string>
#include "Ticket.h"
#include "Ticket_airport.h"

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

	virtual void cancel(int);
	virtual void appointment(int ,int, int );
	virtual void appointment(Ticket_airport*);

	virtual void showTickets(); //꼬인거 풀기 필요
	virtual Ticket* getTicket(int);

	virtual int get_age();
	bool checkData(string, string);
	string get_id();
	string get_name();

	virtual int get_tickets_size();
};

#endif