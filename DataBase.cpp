#include "DataBase.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>


DataBase::DataBase() {
	id = "";
	n = 0;
	start = NULL;
	last = NULL;
}

bool DataBase::sign_in() {
	string password = "";
	UserData* p = start;

	cout << "id >>";
	cin >> id;
	cout << "password >>";
	cin >> password;

	while(p != NULL){
		if (p->checkData(id, password)) {
			User = p;
			return true;
		}
		p = p->next;
	}
	return false;
}
void DataBase::sign_up() {
	cout << "대충 회원가입 화면" << endl;
}

UserData* DataBase::getUser() {
	return User;
}

bool DataBase::check_id() {
	UserData* p = start;
	while(p!= NULL) {
		if (p->get_id() == id) {
			return true;
		}
		p = p->next;
	}
	return false;
}