#ifndef LOGIN_H
#define LOGIN_H
#include "UserData.h"
#include "DataBase.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>

class Login {
	int menu;
	int sign;
	DataBase* LoginDataBase;
public:
	Login();
	UserData getUser();
	void get_menu();
};
#endif