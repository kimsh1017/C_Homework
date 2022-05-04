#ifndef DATABASE_APART_H
#define DATABASE_APART_H
#include "DataBase.h"
#include "DataBase_apart.h"
#include "UserData_apart.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase_apart : public DataBase {
	vector <UserData_apart> Users;
	int n;
public:
	DataBase_apart();
	void sign_up();
	bool sign_in();
	UserData* getUser();
};
#endif
