#ifndef LOGIN_H
#define LOGIN_H
#include "DataBase.h"
#include "UserData.h"

#include <iostream>
using namespace std;
#include<string>

class Login {
	DataBase* LoginDataBase;
	UserData* User;
public:
	Login();
	~Login();
	void sign_up(int);
	UserData* sign_in(int);

	UserData* sign_in_or_up(int);
};
#endif