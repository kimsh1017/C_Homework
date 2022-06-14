#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
#include<string>
#include <Windows.h>
using namespace std;

class Console {
public:
	static string set_id();
	static string set_name();
	static string set_password();
	static int set_place_menu();
	static int set_login_menu();
	static string set_apartment_number();
	static int set_age();
	static void clean(int);
};
#endif
