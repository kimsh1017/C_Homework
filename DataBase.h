#ifndef DATABASE_H
#define DATABASE_H
#include "UserData.h"
#include "DataBase.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>

class DataBase {
	UserData* start;
	UserData* last;
public:
	DataBase();
	~DataBase();

	void sign_up(UserData*, string);
	UserData* sign_in(string,string);
	bool check_id(string);
};
#endif
