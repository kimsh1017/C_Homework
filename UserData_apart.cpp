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
	cout << "��й�ȣ >>";
	cin >> password;
	cout << "�̸� >>";
	cin >> name;
	cout << "���� >>";
	cin >> age;
	cout << "���� (��/��) >>";
	cin >> gender;
}

void UserData_apart::showData() {
	cout << "name: " << name << endl;
	cout << "id : " << id << endl;
	cout << "password:" << password << endl;
	cout << "age:" << age << endl;
	cout << "gender:" << gender << endl;
}