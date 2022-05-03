#ifndef DATABASE_H
#define DATABASE_H
#include "UserData.h"
#include "DataBase_airport.h"
#include "DataBase_apart.h"
#include "DataBase_restaurant.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase {
	vector <UserData> Users;
public:
	void sign_up();
	void sign_in();
};
#endif
