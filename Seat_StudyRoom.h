#ifndef SEAT_STUDYROOM_H
#define SEAT_STUDYROOM_H

#include "UserData.h"
#include "Ticket_apart.h"

#include <iostream>
#include <string>
using namespace std;

class Seat_StudyRoom {
	string name;
	string gender;
public:
	Seat_StudyRoom();
	void appointment(UserData*, Ticket_apart*);
	bool checkSeat();
	string get_gender();
	string get_name();
};

#endif