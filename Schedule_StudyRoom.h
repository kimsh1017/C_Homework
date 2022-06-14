#ifndef SCHEDULE_STUDYROOM_H
#define SCHEDULE_STUDYROOM_H

#include "Seat_StudyRoom.h"
#include "Ticket.h"
#include "Ticket_apart.h"
#include "Console_apart.h"
#include "iomanip"
#include <iostream>
#include <string>
using namespace std;

class Schedule_StudyRoom {
	Seat_StudyRoom** seats;
public:
	Schedule_StudyRoom();
	~Schedule_StudyRoom();

	void appointment(Ticket_apart*);
	void showSeats(string);
	bool checkSeat(int, string);
	bool checkId(string);
	void cancel(Ticket_apart*);
	bool checkAppointed(int);
	int checkGender(string);
};

#endif
