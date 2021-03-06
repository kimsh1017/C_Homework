#ifndef TICKET_APART_H
#define TICKET_APART_H

#include "Ticket.h"
#include "iomanip"

#include <iostream>
#include <string>
using namespace std;

class Ticket_apart :public Ticket {
	int time;
	int seat_number;
	string gender;
public:
	Ticket_apart();
	Ticket_apart(string, string, int, int, int, string);

	void set_time(int);
	void set_seat_number(int);
	void set_gender(string);
	void set_name(string);

	string get_gender();
	string get_name();

	void showTicket();
	int get_time();
	int get_seat_number();
};
#endif

