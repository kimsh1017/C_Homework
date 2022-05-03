#ifndef LOGIN_H
#define LOGIN_H
#include "UserData.h"
#include "DataBase.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class Login {
	DataBase dataBase[3];
public:
	void sign_up();
	void sign_in();
};
#endif