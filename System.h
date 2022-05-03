#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Login.h"

class System {
	int menu;
	Login* login;
	UserData* UserNow;
public:
	void running();
};
#endif