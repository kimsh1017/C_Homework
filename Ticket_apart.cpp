#include "Ticket_apart.h"

Ticket_apart::Ticket_apart() {
	name = "";
	date = 0;
	time = 0;
	gender = "";
}

void Ticket_apart::set_time(int time)
{
	this->time = time;
}

void Ticket_apart::set_seat_number(int seat_number)
{
	this->seat_number= seat_number;
}

void Ticket_apart::set_name(string name) {
	this->name = name;
}
void Ticket_apart::set_gender(string gender) {
	this->gender = gender;
}

string Ticket_apart::get_gender() {
	return gender;
}
string Ticket_apart::get_name() {
	return name;
}
