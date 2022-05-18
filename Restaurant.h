#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "UserData.h"
#include "UserData_restaurant.h"
#include "Schedule_restaurant.h"
#include "Walk_in.h"
#include "Ticket.h"
#include "Ticket_restaurant.h"
#include <deque>
#include <string>
using namespace std;
#include "Console_restaurant.h"

class Restaurant {
	UserData* User;
	Ticket_restaurant* appointment_data;
	Schedule_restaurant* schedules;
	deque <string> walk_in_queue; // list? deque?
	Walk_in* walkInServer;
public:
	Restaurant();
	~Restaurant();
	void sign_in(UserData*);
	void set_date();
	void appointment();
	void cancel();
	void walk_in();
	void runServer(UserData*);
	void showStat();

};
#endif

