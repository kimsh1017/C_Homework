#ifndef SCHEDULE_RESTAURANT_H
#define SCHEDULE_RESTAURNAT_H

#include "Table.h"
#include "Ticket_restaurant.h"
#include <iostream>
#include <string>
using namespace std;
#include "Console_restaurant.h"

class Schedule_restaurant {
	string date;
	Table* tables;
public:
	Schedule_restaurant();
	~Schedule_restaurant();

	void setTableSeat();
	void setDate(string);

	void appointment(Ticket_restaurant* );
	void show_table(Ticket_restaurant*);
	void cancel(Ticket_restaurant* );

	bool checkTable(int);
};
#endif