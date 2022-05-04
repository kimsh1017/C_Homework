#ifndef DATABASE_H
#define DATABASE_H
#include "UserData.h"
#include "DataBase.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase {
	vector <UserData> Users;
	int n;
public:
	DataBase();
	virtual void sign_up();
	virtual bool sign_in();
	virtual UserData* getUser();
};
#endif
