#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
using namespace std;
#include "Ticket_restaurant.h"
#include "Console_restaurant.h"

class Table {
	int seat_number;
	string id;
public:
	Table();
	void set_seat_number(int);
	void appointment(string);
	string get_appointed(int);
	void cancel();
	string get_name();
	string get_id();
};
#endif
