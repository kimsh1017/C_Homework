#ifndef WALK_IN_H
#define WALK_IN_H

#include <iostream>
#include <string>
using namespace std;
#include "Console_restaurant.h"
#include "Table.h"
#include "newUserData.h"
#include <deque>
#include "iomanip"
#include <fstream>

class Walk_in {
	newUserData* User;
	Table* table;
	deque <string> waitingList;
public:
	Walk_in();
	~Walk_in();
	void setWalkInData();

	void running(newUserData*);
	bool checkTableUser();
	bool checkListUser();
	void showTable();
	bool checkTableEmpty();
	void seatTable();
};
#endif

//¦®¦¯¦°¦±¦¬  ¦¡¦¢¦£¦¤¦¥¦¦

