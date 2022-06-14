#include "Ticket.h"

Ticket::Ticket() {
	id = "";
	name = "";
	date = 0;
}
void Ticket::showTicket() {
	cout << "티켓 출력" << endl;
}
void Ticket::set_date(int date) {
	this->date = date;
}
void Ticket::set_id(string id) {
	this->id = id;
}
string Ticket::get_id() {
	return id;
}
string Ticket::get_name() {
	return name;
}


int Ticket::get_date() {
	return date;
}