#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
	string id;
	string name;
	int date;
public:
	Ticket();
	void set_date(int);
	int get_date();

	void set_id(string);
	string get_id();

	string get_name();

	virtual void showTicket();
};
#endif