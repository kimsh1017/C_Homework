#include "Airplane_date.h"
#include "Console_airport.h"

#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Airplane_date::Airplane_date() {
	date = "";
	schedules = new Schedule_airplane[3]; // 시간대 3개

	schedules[0].setTime("07시");
	schedules[1].setTime("12시");
	schedules[2].setTime("17시");
	
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
void Airplane_date::cancel(Ticket* cancel_data) {
	int time = cancel_data->get_time();
	schedules[time - 1].cancel(cancel_data);
}
int Airplane_date::checkAppointed(int seat_number) {
	int result = 0;
	for (int i = 0; i < 3; i++) {
		if (schedules[i].checkAppointed(seat_number)) result++;
	}
	return result;
}
