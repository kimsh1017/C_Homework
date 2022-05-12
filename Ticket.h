#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include <string>
using namespace std;

class Ticket {
protected:
	string name;
	int date;
public:
	Ticket();
	virtual void showTicket();
	virtual int get_date();
	virtual int get_table_number();

	virtual void set_date(int);
	virtual void set_time(int);
	virtual void set_seat(int, int);
};
#endif