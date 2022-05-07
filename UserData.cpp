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