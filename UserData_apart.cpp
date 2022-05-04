#include "UserData.h"
#include "UserData_apart.h"
#include <iostream>
using namespace std;
#include<string>


UserData_apart::UserData_apart() {
	age = 0;
	gender = "";
}

void UserData_apart::createUser(string id) {
	this->id = id;
	cout << "비밀번호 >>";
	cin >> password;
	cout << "이름 >>";
	cin >> name;
	cout << "나이 >>";
	cin >> age;
	cout << "성별 (남/여) >>";
	cin >> gender;
}

void UserData_apart::showData() {
	cout << "name: " << name << endl;
	cout << "id : " << id << endl;
	cout << "password:" << password << endl;
	cout << "age:" << age << endl;
	cout << "gender:" << gender << endl;
}