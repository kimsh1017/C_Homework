#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Login.h"
#include "UserData.h"
#include "Restaurant.h"
#include "Apart.h"

class System {
	Login* login;
	UserData* UserNow;
	Restaurant* restaurant;
	Apart* apart;
public:
	System();
	void running();
};
#endif