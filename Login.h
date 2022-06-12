#ifndef LOGIN_H
#define LOGIN_H

#include <iostream>
using namespace std;
#include<string>
#include "Console.h"

#include "DataBase.h"
#include "AirportUser.h"
#include "RestaurantUser.h"
#include "ApartUser.h"
#include "newUserData.h"

class Login {
	DataBase* LoginDataBase[3];
	newUserData* User;
public:
	Login();
	~Login();
	void sign_up(int);
	void sign_in(int);

	newUserData* sign_in_or_up(int);
	void printGreetMessage(int);
};
#endif