#ifndef TABLE_H
#define TABLE_H

#include <iostream>
#include <string>
using namespace std;
#include "UserData.h"

class Table {
	int seat_number;
	string name;
public:
	Table();
	void set_seat_number(int);
	void appointment(UserData* );
	string get_appointed(int);
	void cancel();
};
#endif
