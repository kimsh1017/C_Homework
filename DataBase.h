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
	int n;
	string id;

	UserData* start;
	UserData* last;
	UserData* User;
public:
	DataBase();
	virtual void sign_up();
	bool sign_in();
	UserData* getUser();
	bool check_id();
};
#endif
