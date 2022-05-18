#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Console.h"

#include "Login.h"
#include "UserData.h"

#include "Restaurant.h"
#include "Apart.h"
#include "Airport.h"

class System {
	Login* login;
	UserData* UserNow;

	Restaurant* restaurant;
	Apart* apart;
	Airport* airport;
public:
	System();
	void running();
};
#endif