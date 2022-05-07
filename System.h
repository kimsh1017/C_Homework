#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Login.h"
#include "UserData.h"
#include "Restaurant.h"

class System {
	Login* login;
	UserData* UserNow;
	Restaurant* restaurant;
public:
	System();
	void running();
};
#endif