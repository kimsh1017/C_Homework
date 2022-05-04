#ifndef LOGIN_H
#define LOGIN_H
#include "DataBase.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>

class Login {
	DataBase* LoginDataBase[3];
	UserData* User;
public:
	Login();
	UserData* getUser();
	void sign_up(int);
	bool sign_in(int);
};
#endif