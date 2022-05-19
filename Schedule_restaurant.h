#ifndef SCHEDULE_RESTAURANT_H
#define SCHEDULE_RESTAURNAT_H

#include "Table.h"
#include "Ticket_restaurant.h"
#include <iostream>
#include <string>
using namespace std;
#include "Console_restaurant.h"

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
	void show_table(Ticket_restaurant*);
	void cancel(int);

	bool checkTable(int);
};
#endif