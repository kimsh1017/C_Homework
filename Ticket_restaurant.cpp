#include "Ticket_restaurant.h"

Ticket_restaurant::Ticket_restaurant() {
	name = "";
	date = 0;
	table_number = 0;
	people = 0;
}

Ticket_restaurant::Ticket_restaurant(string id, int date, int table_number, int people) {
	this->id = id;
	this->date = date;
	this->table_number = table_number;
	this->people = people;
	name = "";
}
void Ticket_restaurant::showTicket() { 
	cout << " -------------------------" << endl;
	cout << "|  [5월 " << this->date << "일]  ";
	cout << this->table_number << "번 테이블  |" << endl;
	cout << "|                         |" << endl;
	cout << "|  인원 : " << people << "명             |" << endl;
	cout << " -------------------------" << endl;
	cout << endl;
}
void Ticket_restaurant::set_table_number(int table_number) {
	this->table_number = table_number;
}
void Ticket_restaurant::set_people(int people) {
	this->people = people;
}

int Ticket_restaurant::get_table_number() {
	return table_number;
}

int Ticket_restaurant::get_people() {
	return people;
}