#include "UserData.h"


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
int UserData::get_mileage() {
	return 0;
}

void UserData::cancel(int n){
	cout << "���� ���" << endl;
}


void UserData::appointment(Ticket_airport* temp) {
	cout << "����" << endl;
}
void UserData::appointment(Ticket_restaurant* temp) {
	cout << "���� ����" << endl;
}
void UserData::appointment(Ticket_apart* temp) {
	cout << "����" << endl;
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