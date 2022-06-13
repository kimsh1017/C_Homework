#include "Seat.h"

Seat::Seat() {
	id = "---";
	cost = 0;
}
void Seat::appointment(Ticket_airport* reservation) {
	this->id = reservation->get_id();
}
string Seat::get_id() {
	return id;
}
void Seat::cancel() {
	this->id = "---";
}

void Seat::set_cost_bussiness() { 
	this->cost = 10;
}
void Seat::set_cost_economy() {
	this->cost = 5;
}
int Seat::get_cost() {
	return cost;
}