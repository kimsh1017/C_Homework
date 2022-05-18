#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>
using namespace std;
#include "UserData.h"
#include "Ticket.h"
#include "Ticket_airport.h"

class Seat {
	string name;
	int cost;
public:
	Seat();
	void appointment(UserData*);
	void set_cost_bussiness();
	void set_cost_economy();
	int get_cost();
	string get_name();
	void cancel();
};
#endif