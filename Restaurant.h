#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "newUserData.h"
#include "UserData_restaurant.h"
#include "Schedule_restaurant.h"
#include "Walk_in.h"
#include "Ticket.h"
#include "Ticket_restaurant.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;
#include "Console_restaurant.h"

class Restaurant {
	newUserData* User;
	Schedule_restaurant* schedules;
	vector <Ticket_restaurant> reservationData; // 예약 정보들
	Walk_in* walkInServer;
public:
	Restaurant();
	~Restaurant();
	void set_date();
	void setReservationData();

	void appointment();
	void cancel();
	void walk_in();
	void runServer(newUserData*);
	void showStat();

};
#endif

