#include "Ticket_apart.h"

Ticket_apart::Ticket_apart() {
	name = "";
	date = 0;
	time = 0;
	gender = "";
	seat_number = 0;
}
Ticket_apart::Ticket_apart(string id, string name, int date, int time, int seat_number, string gender) {
	this->id = id;
	this->name = name;
	this->date = date;
	this->time = time;
	this->seat_number = seat_number;
	this->gender = gender;
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
	cout << " -------------------------- " << endl;
	cout << "| 5�� " << date << "��     " << setw(2) << time << "�� ~ " << setw(2) << time + 1 << "��  |" << endl;
	cout << "| ���� �ڸ� :" << right << setw(3) << seat_number << "��         |" << endl;
	cout << "|                          |" << endl;
	cout << "| ������ : " << left << setw(16) << name << "|" << endl;
	cout << "|  ����  : " << gender << "              |" << endl;
	cout << " -------------------------- " << endl;
}

int Ticket_apart::get_time() {
	return time;
}
int Ticket_apart::get_seat_number() {
	return seat_number;
}