#ifndef AIRPLANE_H
#define AIRPLANE_H

#include <iostream>
#include <string>
using namespace std;
#include "Schedule_airplane.h"

class Airplane {
	string departure;
	string arrival;
	Schedule_airplane* schedules;
public:
	Airplane();
	~Airplane();
	void setDeparture(string);
	void setArrival(string);
	void setDate();

	string getDeparture();
	string getArrival();
};

#endif
