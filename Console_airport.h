#ifndef CONSOLE_AIRPORT_H
#define CONSOLE_AIRPORT_H
#include <iostream>
using namespace std;
#include<string>
#include <Windows.h>
#include "Ticket_airport.h"

class Console_airport {
public:
	static int set_menu(string);
	static int set_date(Ticket_airport*);
	static int set_departure();
	static int set_arrival();
	static int set_time(Ticket_airport*);
	static int set_seat_number();
	static float set_cost();
	static bool check_round_trip();
	static int set_ticket_number(int);
	static int set_stat_menu();
	static void printDataNow(Ticket_airport*);
	static void clean(int);
};
#endif