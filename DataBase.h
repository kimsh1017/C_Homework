#ifndef DATABASE_H
#define DATABASE_H
#include "newUserData.h"

#include <iostream>
using namespace std;
#include<string>
#include<vector>
#include "Console.h"
#include <fstream>

class DataBase {
protected:
	vector <newUserData> userData;
public:
	DataBase();
	virtual ~DataBase();

	virtual void sign_up(string);
	virtual newUserData* sign_in(string,string);
	virtual bool check_id(string);
};
#endif
