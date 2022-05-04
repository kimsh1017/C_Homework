#ifndef USERDATA_H
#define USERDATA_H

#include <iostream>
using namespace std;
#include<string>

class UserData {
	string name;
	string id;
	string password;

public:
	UserData();
	void createUser();
	void changeData();
	void showData();
	bool checkData(string, string);
};

#endif