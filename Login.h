#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
using namespace std;
#include<string>
#include "Console.h"

#include "DataBase.h"
#include "UserData.h"
#include "UserData_airport.h"
#include "UserData_apart.h"
#include "UserData_restaurant.h"

class Login {
	DataBase* LoginDataBase;
	UserData* User;
public:
	Login();
	~Login();
	void sign_up(int);
	void sign_in(int);

	UserData* sign_in_or_up(int);
};
#endif