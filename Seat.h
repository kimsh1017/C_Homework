#ifndef SEAT_H
#define SEAT_H

#include <iostream>
#include <string>
using namespace std;
#include "UserData.h"

class Seat {
	string name;
public:
	Seat();
	void appointment(UserData*);
	string get_name();
	void cancel();
};
#endif