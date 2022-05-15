#ifndef AIRPORT_H
#define AIRPORT_H

#include "UserData.h"
#include "Airplane.h"
#include "Ticket_airport.h"

class Airport {
	UserData* User;
	Airplane** airplane_list; //����� �������� �ٸ� ������
	Ticket_airport* appointment_data;
public:
	Airport();
	~Airport();
	void sign_in(UserData*);
	void setAirplaneDeparture();
	void setAirplaneArrival();
	void show_airplane_list();

	void runServer();
	void appointment();
	void set_route(int, int);
	void cancel();
	void showStat();
};

#endif

