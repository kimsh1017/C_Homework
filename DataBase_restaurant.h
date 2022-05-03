#ifndef DATABASE_APART_H
#define DATABASE_APART_H
#include "DataBase.h"
#include "UserData_apart.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase_apart : public DataBase {
	vector <UserData_apart> Users;
public:
	void sign_up();
	void sign_in();
};
#endif
