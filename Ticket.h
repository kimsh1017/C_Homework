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

	// Ticket_restaurant
	virtual int get_date();
	virtual int get_table_number();

	//Ticket_airport
	virtual int get_departure();
	virtual int get_arrival();
	virtual int get_time();
	virtual int get_seat_type();
	virtual int get_seat_number();

};
#endif