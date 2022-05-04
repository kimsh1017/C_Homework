#ifndef DATABASE_H
#define DATABASE_H
#include "UserData.h"
#include "DataBase.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>

//template <class T>

class DataBase {
protected:
	string id;

	UserData* start;
	UserData* last;
public:
	DataBase();
	~DataBase();
	virtual void sign_up() = 0;
	UserData* sign_in(string,string);
	bool check_id();
};
#endif
