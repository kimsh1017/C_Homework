#include "UserData.h"
#include "UserData_apart.h"
#include <iostream>
using namespace std;
#include<string>


UserData_apart::UserData_apart() { //id, study_room id 로직 변경 필요
	age = 0;
	gender = "";
	apartment_number = "";
	total_time[7] = { 0, };
}

void UserData_apart::createUser(string apartment_number) {
	this->apartment_number = apartment_number;
	this->id = to_string(study_room_id_total);

	cout << "101동 " << this->apartment_number << "호" << endl;
	cout << "독서실 아이디는 :" << this->id << "입니다" << endl;
	cout << "비밀번호 >>";
	cin >> password;
	cout << "이름 >>";
	cin >> name;
	cout << "나이 >>";
	cin >> age;
	cout << "성별 (남/여) >>";
	cin >> gender;

	study_room_id_total++;
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
}
int UserData_apart::getTotalTime(int date) {
	return total_time[date - 1];
}