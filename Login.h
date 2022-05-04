#ifndef LOGIN_H
#define LOGIN_H
#include "DataBase.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>

class Login {
	DataBase** LoginDataBase;
	UserData* User;
public:
	Login();
	~Login();
	void sign_up(int);
	UserData* sign_in(int);
};
#endif