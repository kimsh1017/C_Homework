#ifndef CONSOLE_RESTAURANT_H
#define CONSOLE_RESTAURANT_H
#include <iostream>
using namespace std;
#include<string>

class Console_restaurant {
	static int menu;
	static int date;
	static int people;
public:
	static void set_menu();
	static int get_menu();

	static void set_date();
	static int get_date();

	static void set_people();
	static int get_people();
};
#endif