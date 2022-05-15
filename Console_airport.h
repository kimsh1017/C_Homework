#ifndef CONSOLE_AIRPORT_H
#define CONSOLE_AIRPORT_H
#include <iostream>
using namespace std;
#include<string>

class Console_airport {
public:
	static int set_menu();
	static int set_date();
	static int set_departure();
	static int set_arrival();
	static int set_time();
	static int set_seat_number();
	static float set_cost();
	static bool check_round_trip();
	static int set_ticket_number(int);
	static int set_stat_menu();
};
#endif