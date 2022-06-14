#include "DataBase.h"

DataBase::DataBase() {
}

DataBase::~DataBase() {
}

newUserData* DataBase::sign_in(string id,string password) {
	for (int i = 0; i < userData.size();i++) {
		if (id == userData[i].get_id() && password == userData[i].get_password()) {
			return &userData[i];
		}
	}
	cout << "ID 혹은 비밀번호가 틀립니다" << endl;
	Sleep(1000);
	return NULL;
}

void DataBase::sign_up(string id) {
	string password,name;
	int age;

	password = Console::set_password();
	name = Console::set_name();
	age = Console::set_age();

	userData.push_back(newUserData(id, password, age, name));
}

bool DataBase::check_id(string id) {
	for (int i = 0; i < userData.size();i++) {
		if (id == userData[i].get_id()) {
			return true;
		}
	}
	return false;
}

