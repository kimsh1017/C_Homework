#include "Airplane_date.h"

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

void Airplane_date::appointment(Ticket_airport* reservation) {
	int time;

	if (reservation->get_seat_number() != 0) {
		time = reservation->get_time();
		schedules[time - 1].appointment(reservation);
	}
	else {
		time = Console_airport::set_time(reservation);

		if (time != 0) {
			reservation->set_time(time);
			schedules[time - 1].appointment(reservation);
		}
	}
}
void Airplane_date::cancel(Ticket_airport* cancel_data) {
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
