#ifndef USERDATA_H
#define USERDATA_H

#include <iostream>
using namespace std;
#include<string>

class UserData {
protected:
	string name;
	string id;
	string password;

public:
	UserData* next;
	UserData();
	virtual void createUser(string);
	virtual void showData();
	bool checkData(string, string);
	string get_id();
};

#endif