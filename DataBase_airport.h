#ifndef DATABASE_AIRPORT_H
#define DATABASE_AIRPORT_H
#include "DataBase.h"
#include "UserData_airport.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase_airport : public DataBase {
	vector <UserData_airport> Users;
public:
	void sign_up();
	void sign_in();
};
#endif
