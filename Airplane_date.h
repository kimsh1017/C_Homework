#ifndef AIRPLANE_DATE_H
#define AIRPLANE_DATE_H

#include <iostream>
#include <string>
using namespace std;
#include "Console_airport.h"

#include "Schedule_airplane.h"
#include "Ticket.h"
#include "Ticket_airport.h"

class Airplane_date {
	string date;
	Schedule_airplane* schedules;
public:
	Airplane_date();
	~Airplane_date();
	void setDate(string);
	void appointment(UserData*, Ticket_airport*);
	void cancel(Ticket*);
	int checkAppointed(int);
};

#endif
