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
	cout << "��й�ȣ >>";
	cin >> password;
	cout << "�̸� >>";
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
	cout << "���� ���" << endl;
}

void UserData::appointment(int a, int b, int c) {
	cout << "���� ����" << endl;

}

void UserData::showTickets() {
	cout << "���� Ƽ�� ���" << endl;
}

Ticket* UserData::getTicket(int ticket_number) {
	cout << "���� Ƽ�� ������ ��ȯ" << endl;
	return NULL;
}

int UserData::get_tickets_size() {
	cout << "���� Ƽ�� ������ ���ϱ�" << endl;
	return 0;
}
