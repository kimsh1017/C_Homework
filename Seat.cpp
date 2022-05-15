#include "Seat.h"
#include "Ticket.h"
#include "Ticket_airport.h"
#include <iostream>
#include <string>
using namespace std;

Seat::Seat() {
	name = "---";
	cost = 0;
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

void Seat::set_cost_bussiness() { 
	this->cost = 10;
}
void Seat::set_cost_economy() {
	this->cost = 5;
}
int Seat::get_cost() {
	return cost;
}