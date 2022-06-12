#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include<string>
using namespace std;
#include <Windows.h>

class Console {
public:
	static string set_id();
	static string set_password();
	static int set_place_menu();
	static int set_login_menu();
	static string set_apartment_number();
	static void clean(int);
	static int set_age();
};
#endif
