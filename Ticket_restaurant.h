#ifndef TICKET_RESTAURANT_H
#define TICKET_RESTAURANT_H

#include "Ticket.h"

#include <iostream>
#include <string>
using namespace std;

class Ticket_restaurant :public Ticket{
	int table_number;
	int people;
public:
	Ticket_restaurant();
	void showTicket();
	void set_table_number(int);
	void set_people(int);

	int get_table_number();
	int get_people();
};
#endif