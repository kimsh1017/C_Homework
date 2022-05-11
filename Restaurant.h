#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "UserData.h"
#include "UserData_restaurant.h"
#include "Schedule_restaurant.h"
#include <deque>
#include <string>
using namespace std;

class Restaurant {
	UserData* User;
	Schedule_restaurant* schedules;
	deque <string> walk_in_queue; // list? deque?
	string walk_in_table;
public:
	Restaurant();
	~Restaurant();
	void sign_in(UserData*);
	void set_date();
	void appointment();
	void cancel();
	void walk_in();
	void open();
	void showStat();

	void add_queue();
};
#endif
