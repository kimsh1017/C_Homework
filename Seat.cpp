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

void Seat::set_cost(int cost) { // 가격설정 어떻게 할 것인가 1. 좌석별 다르게  2. 좌석과 경로 모두 다르게 마일리지는 어떻게 사용할 것인가
	this->cost = cost;
}
int Seat::get_cost() {
	return cost;
}