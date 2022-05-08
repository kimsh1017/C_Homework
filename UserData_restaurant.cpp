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
	cout << "비밀번호 >>";
	cin >> password;
	cout << "이름 >>";
	cin >> name;
	cout << "나이 >>";
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
	cout << "대충 취소 화면" << endl;
}

void UserData_restaurant::appointment(int date, int table_number ,int people) {
	tickets.push_back(Ticket_restaurant(date, table_number, people)); //여기서부터 예약 취소 다시 짜기
}

void UserData_restaurant::showTickets() {
	cout << "============================" << endl;
	cout << "현재 보유중인 티켓" << endl;
	for (int i = 0; i < tickets.size(); i++) {
		cout << i+1 << "번 티켓" << endl;
		tickets[i].showTicket();
		cout << "------------------------------" << endl;
	}
}