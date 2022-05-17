#ifndef STUDYROOM_DATE_H
#define STUDYROOM_DATE_H

#include "Schedule_StudyRoom.h"
#include "UserData.h"
#include "Ticket_apart.h"
#include "Console_apart.h"

class StudyRoom_Date {
	Schedule_StudyRoom* schedules;
public:
	StudyRoom_Date();
	~StudyRoom_Date();

	void appointment(UserData*, Ticket_apart*);
};

#endif