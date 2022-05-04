#include "DataBase.h"
#include "UserData.h"
#include "Console.h"
#include <iostream>
using namespace std;
#include<string>
#include<vector>


DataBase::DataBase() {
	n = 0;
}
bool DataBase::sign_in() {
	string id;
	string password;
	cout << "id >>";
	cin >> id;
	cout << "password >>";
	cin >> password;
	for (int i = 0; i < Users.size(); i++) {
		if (Users[i].checkData(id, password)) {
			n = i;
			return true;
		}
	}
	return false;
}
void DataBase::sign_up() {
	cout << "대충 회원가입 화면" << endl;
}

UserData* DataBase::getUser() {
	return &Users[n];
}