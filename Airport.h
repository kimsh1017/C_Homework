#ifndef AIRPORT_H
#define AIRPORT_H

#include "newUserData.h"
#include "Airplane.h"
#include "Ticket.h"
#include "Ticket_airport.h"
#include <fstream>
#include <vector>

#include <iostream>
#include <string>
using namespace std;
#include "Console_airport.h"

class Airport {
	newUserData* User;
	Airplane** airplane_list; //����� �������� �ٸ� ������
	Ticket_airport* appointment_data;

	vector <Ticket_airport> reservationData; //���� ���
public:
	Airport();
	~Airport();
	void setAirplaneDeparture();
	void setAirplaneArrival();
	void show_airplane_list();
	void setReservation();

	void runServer(newUserData*);
	void appointment();
	void set_route(int, int);
	void cancel();
	void showStat();
};

#endif

