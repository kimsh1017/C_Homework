#include "UserData.h"
#include "UserData_restaurant.h"
#include <iostream>
using namespace std;
#include<string>

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