#include "Ticket.h"
#include <iostream>
#include <string>
using namespace std;

Ticket::Ticket() {
	name = "";
	date = 0;
}
void Ticket::showTicket() {
	cout << "티켓 출력" << endl;
}
void Ticket::set_date(int date) {
	this->date = date;
}

int Ticket::get_date() {
	return date;
}
int Ticket::get_table_number() {
	return 0;
}
int Ticket::get_departure() {
	return 0;
}
int Ticket::get_arrival() {
	return 0;
}
int Ticket::get_time() {
	return 0;
}
int Ticket::get_seat_number() {
	return 0;
}
