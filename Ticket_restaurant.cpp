#include "Ticket_restaurant.h"
#include <iostream>
#include <string>
using namespace std;

Ticket_restaurant::Ticket_restaurant(int date, int table_number, int people ) {
	name = ""; //�̸��� �� �ȳ־�
	this->date = date;
	this->table_number = table_number;
	this->people = people;
}
void Ticket_restaurant::showTicket() { // �̸��� �������
	cout << "5�� " << this->date << "��" << endl;
	cout << this->table_number << "�� ���̺� ����" << endl;
	cout << "������ : " << people << endl;
}

int Ticket_restaurant::get_date() {
	return date;
}
int Ticket_restaurant::get_table_number() {
	return table_number;
}
