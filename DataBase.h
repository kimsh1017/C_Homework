#ifndef DATABASE_H
#define DATABASE_H
#include "UserData.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include "Console.h"
#include <fstream>

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
