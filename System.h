#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Login.h"
#include "UserData.h"

class System {
	int place_menu;
	int sign_menu;
	Login* login;
	UserData* UserNow;
public:
	System();
	void get_place();
	void get_sign();
	void running();
};
#endif