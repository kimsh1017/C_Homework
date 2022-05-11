#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
using namespace std;
#include<string>

class Console {
public:
	static string set_id();
	static string set_password();
	static int set_place_menu();
	static int set_login_menu();
};
#endif