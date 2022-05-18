#ifndef WALK_IN_H
#define WALK_IN_H

#include <iostream>
#include <string>
using namespace std;
#include "Console_restaurant.h"
#include "Table.h"
#include "UserData.h"
#include <deque>
#include "iomanip"

class Walk_in {
	UserData* User;
	Table* table;
	deque <string> waitingList;
public:
	Walk_in();
	~Walk_in();

	void running(UserData*);
	bool checkTableUser();
	bool checkListUser();
	void showTable();
	bool checkTableEmpty();
	void seatTable();
};
#endif

//¦®¦¯¦°¦±¦¬  ¦¡¦¢¦£¦¤¦¥¦¦

