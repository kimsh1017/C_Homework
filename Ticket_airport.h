#ifndef TICKET_AIRPORT_H
#define TICKET_AIRPORT_H

#include "Ticket.h"

#include <iostream>
#include <string>
using namespace std;

class Ticket_airport:public Ticket {
	int departure;
	int arrival;
	int time;
	int seat_number;

public:
	Ticket_airport();
	void set_route(int, int);
	void set_time(int);
	void set_seat_number(int);
	void showTicket();

	int get_departure();
	int get_arrival();
	int get_time();
	int get_seat_number();
};
#endif
