#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <string>
using namespace std;
#include "Airplane_date.h"
#include "Ticket_airport.h"

class Airplane {
	string departure;
	string arrival;
	Airplane_date* airplane_date;
public:
	Airplane();
	~Airplane();
	void setDeparture(string);
	void setArrival(string);
	void setDate();

	string getDeparture();
	string getArrival();
	void appointment(UserData*, Ticket_airport*);
};

#endif
