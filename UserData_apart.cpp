#include "UserData_apart.h"


UserData_apart::UserData_apart() { //id, study_room id 로직 변경 필요
	age = 0;
	gender = "";
	apartment_number = "";
	for (int i = 0; i < 7; i++) {
		total_time[i] = 0;
	}
}

void UserData_apart::createUser(string apartment_number) {
	fstream fout("DataBase.txt", ios::app | ios::out);

	this->apartment_number = apartment_number;
	this->id = to_string(study_room_id_total);
	cout << endl;
	cout << "101동 " << this->apartment_number << "호" << endl;
	cout << "독서실 아이디는 :" << this->id << "입니다" << endl;
	cout << endl;
	cout << "비밀번호 >>";
	cin >> password;

	study_room_id_total++;

	fout << "***\n";
	fout << id << "/" << password << "/" << apartment_number << "\n";
}

void UserData_apart::showData() {
	cout << "세대 호수" << apartment_number << endl;
	cout << "name: " << name << endl;
	cout << "id : " << id << endl;
	cout << "password:" << password << endl;
	cout << "age:" << age << endl;
	cout << "gender:" << gender << endl;
}

string UserData_apart::get_id() { //이름 변경 ? get_id -> checkSignedUp; 
	return apartment_number; // 아파트 호수 중복 체크
}

void UserData_apart::appointment(Ticket_apart* appointment_data) {
	tickets.push_back(*appointment_data);
	total_time[appointment_data->get_date() - 1]++;
}
int UserData_apart::getTotalTime(int date) {
	return total_time[date - 1];
}

void UserData_apart::showTickets() {
	Console_apart::clean(0);
	cout << endl;
	cout << "[101동 " <<id  << "호] 현재 예약 목록" << endl;
	cout << endl;

	for (int i = 0; i < tickets.size(); i++) {
		cout << i + 1 << "번 예약" << endl;
		tickets[i].showTicket();
		cout << endl;
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
