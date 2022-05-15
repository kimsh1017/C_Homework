#ifndef SCHEDULE_AIRPLANE_H
#define SCHEDULE_AIRPLANE_H

#include <iostream>
#include <string>
using namespace std;
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
	void appointment(UserData*, Ticket_airport*);
	void showSeats(float);
	void cancel(Ticket*);
};

#endif
