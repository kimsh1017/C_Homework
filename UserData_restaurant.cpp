#include "UserData.h"
#include "UserData_restaurant.h"
#include <iostream>
using namespace std;
#include <string>
#include <vector>
#include "Table.h"

UserData_restaurant::UserData_restaurant() {
	age = 0;
}

void UserData_restaurant::createUser(string id) {
	this->id = id;
	cout << "��й�ȣ >>";
	cin >> password;
	cout << "�̸� >>";
	cin >> name;
	cout << "���� >>";
	cin >> age;
}

void UserData_restaurant::showData() {
	cout << "name: " << name << endl;
	cout << "id : " << id << endl;
	cout << "password:" << password << endl;
	cout << "age:" << age << endl;
}

int UserData_restaurant::get_age() {
	return age;
}

void UserData_restaurant::cancel(int ticket_number) {
	tickets.erase(tickets.begin() + ticket_number - 1);
}

void UserData_restaurant::appointment(int date, int table_number ,int people) {
	tickets.push_back(Ticket_restaurant(date, table_number, people));
}

void UserData_restaurant::showTickets() {
	cout << "============================" << endl;
	cout << "���� �������� Ƽ��" << endl;
	for (int i = 0; i < tickets.size(); i++) {
		cout << i+1 << "�� Ƽ��" << endl;
		tickets[i].showTicket();
		cout << "------------------------------" << endl;
	}
}

Ticket* UserData_restaurant::getTicket(int ticket_number) {
	// 0�϶� ����ó�� & �ݺ�?
	if (ticket_number == 0) {
		return NULL;
	}
	else {
		return &tickets[ticket_number - 1];
	}
}

int UserData_restaurant::get_tickets_size() {
	int temp = tickets.size();
	return temp;
}