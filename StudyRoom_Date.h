#ifndef STUDYROOM_DATE_H
#define STUDYROOM_DATE_H

#include "Schedule_StudyRoom.h"
#include "Ticket.h"
#include "Ticket_apart.h"
#include "Console_apart.h"
#include <iostream>
using namespace std;

class StudyRoom_Date {
	Schedule_StudyRoom* schedules;
public:
	StudyRoom_Date();
	~StudyRoom_Date();

	void appointment(Ticket_apart*);
	int set_time(Ticket_apart*);
	void cancel(Ticket_apart*);
	int check_seat(int);
	int check_gender(string);
};

#endif