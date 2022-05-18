#ifndef CONSOLE_RESTAURANT_H
#define CONSOLE_RESTAURANT_H
#include <iostream>
using namespace std;
#include <string>
#include <Windows.h>


class Console_restaurant {
public:
	static int set_menu();
	static int set_date();
	static int set_people();
	static int set_table();

	static int set_ticket_number(int);
	static int set_stat_menu();
	static int set_walk_in_people();
};
#endif
