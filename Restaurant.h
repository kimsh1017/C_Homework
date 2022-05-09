#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "UserData.h"
#include "UserData_restaurant.h"
#include "Schedule_restaurant.h"
#include <queue>
#include <string>
using namespace std;

class Restaurant {
	UserData* User;
	Schedule_restaurant* schedules;
	queue <string> walk_in_queue;
public:
	Restaurant();
	void sign_in(UserData*);
	void set_date();
	void appointment();
	void cancel();
	void walk_in();
	void open();

	void add_queue();
};
#endif
