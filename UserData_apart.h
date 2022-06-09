#ifndef USERDATA_APART_H
#define USERDATA_APART_H
#include <iostream>
using namespace std;
#include<string>

#include <vector>
#include "Ticket.h"
#include "Ticket_apart.h"
#include "UserData.h"
#include "Console_apart.h"

#include <fstream>


class UserData_apart : public UserData {
	int age;
	string gender;
	string apartment_number;
	static int study_room_id_total;
	vector <Ticket_apart> tickets;
	int total_time[7];

public:
	UserData_apart();
	void createUser(string);
	void showData();
	string get_id();
	void appointment(Ticket_apart*);
	int getTotalTime(int);

	void showTickets();
	int get_tickets_size();
	Ticket* getTicket(int);
	void cancel(int);
};

#endif
