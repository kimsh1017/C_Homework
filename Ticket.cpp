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

int Ticket::get_date() {
	return 0;
}
int Ticket::get_table_number() {
	return 0;
}

void Ticket::set_date(int a) {
	// setDate
}
void Ticket::set_time(int a) {
	// setTime
}
void Ticket::set_seat(int a,int b) {
	// setSeat
}