#include "UserData.h"
#include "UserData_apart.h"
#include <iostream>
using namespace std;
#include<string>


UserData_apart::UserData_apart() { //id, study_room id ���� ���� �ʿ�
	age = 0;
	gender = "";
	apartment_number = "";
	for (int i = 0; i < 7; i++) {
		total_time[i] = 0;
	}
}

void UserData_apart::createUser(string apartment_number) {
	this->apartment_number = apartment_number;
	this->id = to_string(study_room_id_total);

	cout << "101�� " << this->apartment_number << "ȣ" << endl;
	cout << "������ ���̵�� :" << this->id << "�Դϴ�" << endl;
	cout << "��й�ȣ >>";
	cin >> password;

	study_room_id_total++;
}

void UserData_apart::showData() {
	cout << "���� ȣ��" << apartment_number << endl;
	cout << "name: " << name << endl;
	cout << "id : " << id << endl;
	cout << "password:" << password << endl;
	cout << "age:" << age << endl;
	cout << "gender:" << gender << endl;
}

string UserData_apart::get_id() { //�̸� ���� ? get_id -> checkSignedUp; 
	return apartment_number; // ����Ʈ ȣ�� �ߺ� üũ
}

void UserData_apart::appointment(Ticket_apart* appointment_data) {
	tickets.push_back(*appointment_data);
	total_time[appointment_data->get_date() - 1]++;
}
int UserData_apart::getTotalTime(int date) {
	return total_time[date - 1];
}

void UserData_apart::showTickets() {
	cout << "============================" << endl;
	cout << "���� ���� ���" << endl;
	cout << "------------------------------" << endl;
	for (int i = 0; i < tickets.size(); i++) {
		cout << i + 1 << "��" << endl;
		tickets[i].showTicket();
		cout << "------------------------------" << endl;
	}
}

int UserData_apart::get_tickets_size() {
	int temp = tickets.size();
	return temp;
}

Ticket* UserData_apart::getTicket(int ticket_number) {
	return &tickets[ticket_number - 1];
}
void UserData_apart::cancel(int ticket_number) {
	tickets.erase(tickets.begin() + ticket_number - 1);
}
