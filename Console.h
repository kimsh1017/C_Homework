#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
using namespace std;
#include<string>

class Console {
	static int place_menu;
	static int login_menu;

	static string id;
	static string password;
public:
	static void set_id();
	static string get_id();

	static void set_password();
	static string get_password();

	static void set_place_menu();
	static int get_place_menu();

	static void set_login_menu();
	static int get_login_menu();

};
#endif