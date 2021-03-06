#ifndef SCHEDULE_AIRPLANE_H
#define SCHEDULE_AIRPLANE_H

#include <iostream>
#include <string>
using namespace std;
#include "Console_airport.h"

#include "Seat.h"
#include "Ticket.h"
#include "Ticket_airport.h"

class Schedule_airplane {
	string time;
	Seat* seats;
public:
	Schedule_airplane();
	~Schedule_airplane();
	void set_seat_cost();
	void setTime(string);
	void appointment(Ticket_airport*);
	void showSeats(float, Ticket_airport*);
	void cancel(Ticket_airport*);
	bool checkAppointed(int);
};

#endif
