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
	UserData();
	UserData* next;

	virtual void createUser(string);
	virtual void showData();
	virtual void cancel(int);
	virtual void appointment(int,int, int );

	virtual void showTickets();
	virtual int get_age();
	bool checkData(string, string);
	string get_id();
	string get_name();
};

#endif