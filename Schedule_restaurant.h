#ifndef SCHEDULE_RESTAURANT_H
#define SCHEDULE_RESTAURNAT_H

#include "Table.h"
#include <iostream>
#include <string>
#include "Ticket_restaurant.h"
using namespace std;

class Schedule_restaurant {
	UserData* User;
	string date;
	Table* reservation_4;
public:
	Schedule_restaurant();
	~Schedule_restaurant();

	void setTableSeat();
	void setDate(string);

	void appointment(UserData*,Ticket_restaurant* );
	void show_table(int);
	void cancel(int);

	bool checkTable(int);
};
#endif