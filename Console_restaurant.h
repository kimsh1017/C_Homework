#ifndef CONSOLE_RESTAURANT_H
#define CONSOLE_RESTAURANT_H
#include <iostream>
using namespace std;
#include<string>

class Console_restaurant {
	static int ticket_number;
public:
	static int set_menu();

	static int set_date();

	static int set_people();

	static int set_table();

	void static set_ticket_number();
	int static get_ticket_number();
};
#endif
