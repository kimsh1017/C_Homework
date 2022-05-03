#ifndef USERDATA_RESTAURANT_H
#define USERDATA_RESTAURANT_H
#include <iostream>
using namespace std;
#include<string>
#include "UserData.h"

class UserData_restaurant : public UserData {
	int age;
	string gender;
public:
	UserData_restaurant();
};

#endif