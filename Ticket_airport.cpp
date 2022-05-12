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
	cout << "5월 " << this->date << "일" << endl;
	cout << departure << "->" << arrival << endl;
	cout << "시간대" << time << endl;
	cout << seat_type << "-" << seat_number << "번 좌석" << endl;
}
