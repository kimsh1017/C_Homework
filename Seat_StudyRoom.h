#ifndef SEAT_STUDYROOM_H
#define SEAT_STUDYROOM_H

#include "Ticket_apart.h"
#include "Console_apart.h"

#include <iostream>
#include <string>
using namespace std;

class Seat_StudyRoom {
	string id;
	string gender;
public:
	Seat_StudyRoom();
	void appointment(Ticket_apart*);
	bool checkSeat();
	string get_gender();
	string get_id();
	void cancel();
};

#endif