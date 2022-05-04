#ifndef DATABASE_AIRPORT_H
#define DATABASE_AIRPORT_H
#include "DataBase.h"
#include "DataBase_airport.h"
#include "UserData_airport.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase_airport : public DataBase {
	
public:
	void sign_up();
};
#endif
