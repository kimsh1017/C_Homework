#ifndef APART_H
#define APART_H

#include "StudyRoom_Date.h"
#include "UserData.h"
#include "UserData_apart.h"
#include "Console_apart.h"
#include "Ticket_apart.h"

class Apart {
	StudyRoom_Date* studyRoom_Date;
	UserData* User;
public:
	Apart();
	~Apart();

	void runserver(UserData*);
	void appointment();
	void cancel();
	void showStat();
};

#endif
