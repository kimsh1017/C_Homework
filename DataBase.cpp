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

	fstream fin("DataBase.txt", ios::in);
	string temp;
	string fileId, filePassword;

	while (getline(fin,temp)) { //이 부분 로직 효율적으로 바꿀 생각
		if (temp == "***") {
			getline(fin, fileId, '/');
			getline(fin, filePassword, '/');
			cout <<"id: "<< fileId << " " <<"ps: " << filePassword << endl;
			Sleep(1000);
			getline(fin, temp);

			if (id == fileId && password == filePassword) {
				cout << "파일 로그인 성공" << endl;
			}
		}
	}

	while(p != NULL){
		if (p->checkData(id, password)) {
			return p;
		}
		p = p->next;
	}
	cout << "회원정보가 올바르지 않습니다" << endl;
	Sleep(1000);
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

