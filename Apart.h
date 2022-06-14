#ifndef APART_H
#define APART_H

#include "StudyRoom_Date.h"
#include "newUserData.h"
#include "Ticket.h"
#include "Ticket_apart.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Console_apart.h"
using namespace std;

class Apart {
	StudyRoom_Date* studyRoom_Date;
	newUserData* User;
	vector <Ticket_apart> reservationData;
public:
	Apart();
	~Apart();
	void setReservationData();

	void runserver(newUserData*);
	void appointment();
	void cancel();
	void showStat();
};

#endif
