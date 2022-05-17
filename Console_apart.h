#ifndef CONSOLE_APART_H
#define CONSOLE_APART_H
#include <iostream>
using namespace std;
#include<string>

class Console_apart {
public:
	static int set_menu();
	static int set_date();
	static int set_time(int);
	static string set_gender();
	static string set_name();
	static int set_seat_number();
	static int set_age();
	static int set_ticket_number(int);
	static int set_stat_menu();
	static int set_stat_detail();
};
#endif
