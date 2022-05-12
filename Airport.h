#ifndef AIRPORT_H
#define AIRPORT_H

#include "UserData.h"
#include "Airplane.h"

class Airport {
	UserData* User;
	Airplane** airplane_list; //����� �������� �ٸ� ������
public:
	Airport();
	~Airport();
	void sign_in(UserData*);
	void setAirplaneDeparture();
	void setAirplaneArrival();
	void show_airplane_list();

	void runServer();

};

#endif

