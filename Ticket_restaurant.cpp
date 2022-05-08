#include "Ticket_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

Ticket_restaurant::Ticket_restaurant(int date, int table_number, int people , Table* table) {
	name = "";
	this->date = date;
	this->table_number = table_number;
	this->people = people;
	this->table = table;
}
void Ticket_restaurant::showTicket() {
	cout << "5월 " << this->date << "일" << endl;
	cout << this->table_number << "번 테이블 예약" << endl;
	cout << "동반인 : " << people << endl;
}

