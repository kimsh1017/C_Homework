#include "Ticket_airport.h"
#include "Ticket.h"

#include <iostream>
#include <string>
using namespace std;

Ticket_airport::Ticket_airport() {
	departure = 0;
	arrival = 0;
	time = 0;
	date = 0;
	seat_type = 0;
	seat_number = 0;
}

void Ticket_airport::set_route(int departure, int arrival) {
	this->departure = departure;
	this->arrival = arrival;
}
void Ticket_airport::set_date(int date) {
	this->date = date;
}
void Ticket_airport::set_time(int time) {
	this->time = time;
}
void Ticket_airport::set_seat(int seat_type, int seat_number) {
	this->seat_type = seat_type;
	this->seat_number = seat_number;
}
void Ticket_airport::showTicket() {
	string airport_list[5] = { "인천","김포","제주","김해","대구" };
	string string_time;

	switch (time) {
	case 1:
		string_time = "07시";
		break;
	case 2:
		string_time = "12시";
		break;
	case 3:
		string_time = "17시";
		break;
	}

	cout << "5월 " << this->date << "일 " << string_time << endl;
	cout << airport_list[departure - 1] << "->" << airport_list[arrival - 1] << endl;

	if (seat_type == 1) {
		cout << "이코노미 클래스" << seat_number << "번 좌석" << endl;
	}
	else {
		cout << "비즈니스 클래스" << seat_number << "번 좌석" << endl;
	}
}

int Ticket_airport::get_date() {
	return date;
}
int Ticket_airport::get_departure() {
	return departure;
}
int Ticket_airport::get_arrival() {
	return arrival;
}
int Ticket_airport::get_time() {
	return time;
}
int Ticket_airport::get_seat_type() {
	return seat_type;
}
int Ticket_airport::get_seat_number() {
	return seat_number;
}
