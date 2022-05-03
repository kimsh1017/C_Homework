#ifndef USERDATA_H
#define USERDATA_H

#include "UserData_airport.h"
#include "UserData_restaurant.h"
#include "UserData_apart.h"

#include <iostream>
using namespace std;
#include<string>

class UserData {
	string name;
	string id;
	string password;

public:
	UserData();
	void createUser();
	void changeData();
	void showData();
	bool checkData(string, string);
};

#endif