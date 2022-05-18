#include "DataBase.h"

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
	cout << "ȸ�������� �ùٸ��� �ʽ��ϴ�" << endl;
	return NULL;
}

void DataBase::sign_up(UserData* newUser, string id) {
	if (start == NULL) {
		start = newUser;
		last = start;
	}
	else {
		last->next = newUser;
		last = last->next;
	}
	last->createUser(id);
}

bool DataBase::check_id(string id) {
	UserData* p = start;
	while(p!= NULL) {
		if (p->get_id() == id) {
			return true;
		}
		p = p->next;
	}
	return false;
}

