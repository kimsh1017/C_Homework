#include "Seat.h"
#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Seat::Seat() {
	name = "---";
}
void Seat::appointment(UserData* User) {
	this->name = User->get_name();
}
string Seat::get_name() {
	return name;
}
void Seat::cancel() {
	this->name = "---";
}