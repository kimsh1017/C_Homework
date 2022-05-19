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
	cout << "| ������ : " << name << "  ���� : " << gender << " |" << endl;
	cout << "|                         |" << endl;
	cout << "| 5�� " << date << "��  " << time << "�� ~ " << time+1 << "��     |" << endl;
	cout << "| "<< seat_number << "�� �ڸ� ����           |" << endl;
	cout << " ------------------------- " << endl;
}

int Ticket_apart::get_time() {
	return time;
}
int Ticket_apart::get_seat_number() {
	return seat_number;
}