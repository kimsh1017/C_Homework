#include "UserData.h"
#include "Console.h"

#include <iostream>
using namespace std;
#include<string>


UserData::UserData() {
	name = "";
	id = "";
	password = "";
}
void UserData::createUser() {
	cout << "�̸� >>";
	name = Console::get_string();
	cout << "ID >>";
	id = Console::get_string();
	cout << "��й�ȣ >>";
	password = Console::get_string();

}
void UserData::showData() {
	cout << "name: " << name << endl;
	cout << "id : " << id << endl;
	cout << "password" << password << endl;
}

bool UserData::checkData(string id, string password) {
	return (this->id == id && this->password == password);
}