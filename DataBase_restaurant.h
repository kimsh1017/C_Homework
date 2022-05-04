#ifndef DATABASE_RESTAURANT_H
#define DATABASE_RESTAURANT_H

#include "DataBase.h"
#include "DataBase_restaurant.h"
#include "UserData_restaurant.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase_restaurant : public DataBase {
public:
	void sign_up();
};
#endif
