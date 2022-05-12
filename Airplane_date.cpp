#include "Airplane_date.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Airplane_date::Airplane_date() {
	date = "";
	schedules = new Schedule_airplane[3]; // �ð��� 3��

	schedules[0].setTime("07��");
	schedules[1].setTime("12��");
	schedules[2].setTime("17��");
	
}
Airplane_date::~Airplane_date() {
	delete[]schedules;
}
void Airplane_date::setDate(string date) {
	this->date = date;
}

void Airplane_date::appointment(UserData* User,Ticket_airport* appointment_data) {
	int time;

	time = Console_airport::set_time();
	appointment_data->set_time(time);
	schedules[time - 1].appointment(User,appointment_data);
}
