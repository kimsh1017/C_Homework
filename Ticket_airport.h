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
	int seat_type;
	int seat_number;

public:
	Ticket_airport();
	void set_route(int, int);
	void set_date(int);
	void set_time(int);
	void set_seat(int, int);
	void showTicket();
};
#endif
