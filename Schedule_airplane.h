#ifndef SCHEDULE_AIRPLANE_H
#define SCHEDULE_AIRPLANE_H

#include <iostream>
#include <string>
using namespace std;
#include "Seat.h"
#include "Ticket_airport.h"

class Schedule_airplane {
	string time;
	Seat* economy;
	Seat* bussiness;
public:
	Schedule_airplane();
	~Schedule_airplane();
	void setTime(string);
	void appointment(UserData*, Ticket_airport*);
	void showSeats();
};

#endif
