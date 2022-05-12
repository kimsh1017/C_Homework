#include "UserData.h"
#include "Console.h"

#include <iostream>
using namespace std;
#include<string>


UserData::UserData() {
	name = "";
	id = "";
	password = "";
	next = NULL;
}

void UserData::createUser(string id) {
	this->id = id;
	cout << "비밀번호 >>";
	cin >> password;
	cout << "이름 >>";
	cin >> name;
}
void UserData::showData() {
	cout << "name: " << name << endl;
	cout << "id : " << id << endl;
	cout << "password" << password << endl;
}

bool UserData::checkData(string id, string password) {
	return (this->id == id && this->password == password);
}

string UserData::get_id() {
	return id;
}
string UserData::get_name() {
	return name;
}

int UserData::get_age() {
	return 0;
}

void UserData::cancel(int n){
	cout << "대충 취소" << endl;
}

void UserData::appointment(int a, int b, int c) {
	cout << "대충 예약" << endl;

}

void UserData::showTickets() {
	cout << "대충 티켓 출력" << endl;
}

Ticket* UserData::getTicket(int ticket_number) {
	cout << "대충 티켓 포인터 반환" << endl;
	return NULL;
}

int UserData::get_tickets_size() {
	cout << "대충 티켓 사이즈 구하기" << endl;
	return 0;
}
