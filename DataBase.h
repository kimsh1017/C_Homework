#ifndef DATABASE_H
#define DATABASE_H
#include "UserData.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase {
	vector <UserData> Users;

	string id;
	string password;
public:
	void sign_up(int);
	void sign_in();
};
#endif
