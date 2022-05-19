#include "Seat.h"

Seat::Seat() {
	name = "---";
	cost = 0;
}
void Seat::appointment(UserData* User) {
	this->name = User->get_name();
	cout << User->get_name() << "님 예약되었습니다" << endl;
	Sleep(1000);
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