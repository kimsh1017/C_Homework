#include "DataBase.h"

DataBase::DataBase() {
}

DataBase::~DataBase() {
}

newUserData* DataBase::sign_in(string id,string password) {
	for (int i = 0; i < userData.size();i++) {
		if (id == userData[i].get_id() && password == userData[i].get_password()) {
			cout << "파일 로그인 성공" << endl;
			return &userData[i];
		}
	}
	cout << "로그인에 실패했습니다" << endl;
	return NULL;
}

void DataBase::sign_up(string id) {
	string password;
	int age;

	password = Console::set_password();
	age = Console::set_age();

	userData.push_back(newUserData(id, password, age));
}

bool DataBase::check_id(string id) {
	for (int i = 0; i < userData.size();i++) {
		if (id == userData[i].get_id()) {
			return true;
		}
	}
	return false;
}

