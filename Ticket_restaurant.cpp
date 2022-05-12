#include "Ticket_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

Ticket_restaurant::Ticket_restaurant(int date, int table_number, int people ) {
	name = ""; //이름은 왜 안넣어
	this->date = date;
	this->table_number = table_number;
	this->people = people;
}
void Ticket_restaurant::showTicket() { // 이름도 출력해줘
	cout << "5월 " << this->date << "일" << endl;
	cout << this->table_number << "번 테이블 예약" << endl;
	cout << "동반인 : " << people << endl;
}

int Ticket_restaurant::get_date() {
	return date;
}
int Ticket_restaurant::get_table_number() {
	return table_number;
}
