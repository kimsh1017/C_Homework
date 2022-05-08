#ifndef TICKET_RESTAURANT_H
#define TICKET_RESTAURANT_H

#include "Ticket.h"
#include "Table.h"

#include <iostream>
#include <string>
using namespace std;

class Ticket_restaurant :public Ticket{
	int table_number;
	int people;
	Table* table;
public:
	Ticket_restaurant(int, int, int, Table*);
	void showTicket();
};
#endif