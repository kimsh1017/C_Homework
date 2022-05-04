#ifndef SYSTEM_H
#define SYSTEM_H
#include <iostream>
using namespace std;
#include <string>
#include "Login.h"
#include "UserData.h"

class System {
	Login* login;
	UserData* UserNow;
public:
	System();
	void running();
};
#endif