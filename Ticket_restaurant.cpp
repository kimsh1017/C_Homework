#include "Ticket_restaurant.h"

Ticket_restaurant::Ticket_restaurant() {
	name = "";
	date = 0;
	table_number = 0;
	people = 0;
}
void Ticket_restaurant::showTicket() { 
	cout << " -------------------------" << endl;
	cout << "|  [5�� " << this->date << "��]  ";
	cout << this->table_number << "�� ���̺�  |" << endl;
	cout << "|                         |" << endl;
	cout << "|  �ο� : " << people << "��             |" << endl;
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