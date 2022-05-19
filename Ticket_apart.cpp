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

void Ticket_apart::showTicket() {
	cout << " ------------------------- " << endl;
	cout << "| 예약자 : " << name << "  성별 : " << gender << " |" << endl;
	cout << "|                         |" << endl;
	cout << "| 5월 " << date << "일  " << time << "시 ~ " << time+1 << "시     |" << endl;
	cout << "| "<< seat_number << "번 자리 예약           |" << endl;
	cout << " ------------------------- " << endl;
}

int Ticket_apart::get_time() {
	return time;
}
int Ticket_apart::get_seat_number() {
	return seat_number;
}