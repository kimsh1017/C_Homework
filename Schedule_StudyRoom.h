#ifndef SCHEDULE_STUDYROOM_H
#define SCHEDULE_STUDYROOM_H

#include "Seat_StudyRoom.h"
#include "UserData.h"
#include "Ticket_apart.h"
#include "Console_apart.h"


class Schedule_StudyRoom {
	Seat_StudyRoom** seats;
public:
	Schedule_StudyRoom();
	~Schedule_StudyRoom();

	void appointment(UserData*, Ticket_apart*);
	void showSeats(string);
	bool checkSeat(int, string);
};

#endif
