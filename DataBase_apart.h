#ifndef DATABASE_RESTAURANT_H
#define DATABASE_RESTAURANT_H
#include "DataBase.h"
#include "UserData_restaurant.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase_restaurant : public DataBase {
	vector <UserData_restaurant> Users;
public:
	void sign_up();
	void sign_in();
};
#endif
