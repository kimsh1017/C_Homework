#include "DataBase.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>


DataBase::DataBase() {
	start = NULL;
	last = NULL;
}
DataBase::~DataBase() {
	UserData* p = start;
	UserData* temp = p;
	while (p != NULL) {
		temp = p->next;
		delete p;
		p = temp;
	}
}

UserData* DataBase::sign_in(string id,string password) {
	UserData* p = start;

	while(p != NULL){
		if (p->checkData(id, password)) {
			return p;
		}
		p = p->next;
	}
	cout << "회원정보가 올바르지 않습니다" << endl;
	return NULL;
}

void DataBase::sign_up(UserData* newUser) {
	if (start == NULL) {
		start = newUser;
		last = start;
	}
	else {
		last->next = newUser;
		last = last->next;
	}
	last->createUser(Console::get_id());
}

bool DataBase::check_id() {
	UserData* p = start;
	while(p!= NULL) {
		if (p->get_id() == Console::get_id()) {
			return true;
		}
		p = p->next;
	}
	return false;
}

