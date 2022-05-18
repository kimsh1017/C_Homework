#ifndef AIRPORT_H
#define AIRPORT_H

#include "UserData.h"
#include "Airplane.h"
#include "Ticket.h"
#include "Ticket_airport.h"

#include <iostream>
#include <string>
using namespace std;
#include "Console_airport.h"

class Airport {
	UserData* User;
	Airplane** airplane_list; //출발지 도착지가 다른 비행기들
	Ticket_airport* appointment_data;
public:
	Airport();
	~Airport();
	void setAirplaneDeparture();
	void setAirplaneArrival();
	void show_airplane_list();

	void runServer(UserData*);
	void appointment();
	void set_route(int, int);
	void cancel();
	void showStat();
};

#endif

