#include "Ticket_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

Ticket_restaurant::Ticket_restaurant() {
	name = "";
	date = 0;
	table_number = 0;
	people = 0;
}
void Ticket_restaurant::showTicket() { // 이름도 출력해줘
	cout << "5월 " << this->date << "일" << endl;
	cout << this->table_number << "번 테이블 예약" << endl;
	cout << "동반인 : " << people << endl;
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
