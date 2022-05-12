#ifndef AIRPLANE_DATE_H
#define AIRPLANE_DATE_H

#include <iostream>
#include <string>
using namespace std;
#include "Schedule_airplane.h"

class Airplane_date {
	string date;
	Schedule_airplane* schedules;
public:
	Airplane_date();
	~Airplane_date();
	void setDate(string);
	void appointment(UserData*);
};

#endif
