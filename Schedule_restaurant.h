#ifndef SCHEDULE_RESTAURANT_H
#define SCHEDULE_RESTAURNAT_H

#include "Table.h"
#include <iostream>
#include <string>
using namespace std;

class Schedule_restaurant {
	UserData* User;
	string date;
	Table* reservation_4;
	Table* reservation_6;
public:
	Schedule_restaurant();
	void setTableSeat();
	void setDate(string);
	void appointment(UserData*);
	void show_table(int);
};
#endif